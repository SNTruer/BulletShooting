//
//  Player.cpp
//  TestProject
//
//  Created by 이명준 on 2015. 10. 27..
//
//

#include "Player.h"
#define COCOS2D_DEBUG 1

Player::Player(Vec2 pos){
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
    keyListener->onKeyReleased = CC_CALLBACK_2(Player::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
    
    playerSprite = Sprite::create("testbox.png");
    playerSprite->setScale(playerSizeWidth / playerSprite->getContentSize().width, playerSizeHeight / playerSprite->getContentSize().height);

	colBoxRadius = PLAYER_COL_BOX_RADIUS;
    
    this->setPosition(pos);
    
    this->addChild(playerSprite);
    
    colBoxSprite = Sprite::create("colbox.png");
    colBoxSprite->setScale(colBoxRadius*2 / colBoxSprite->getContentSize().width, colBoxRadius*2 / colBoxSprite->getContentSize().height);

    this->addChild(colBoxSprite);
    
    this->schedule(schedule_selector(Player::update));
    
    setAliveFlag(true);
	setInvincibleFlag(false);
}

void Player::update(float dt)
{
    move();
    shot();
	spriteChange();
}

void Player::move()
{
    if(!aliveFlag) return;
    
    auto pos = this->getPosition();
    float xSpeed = 0, ySpeed = 0;
    
    //move
    if(std::find(heldKeys.begin(), heldKeys.end(), RIGHT_ARROW) != heldKeys.end()) xSpeed = 1;
    else if(std::find(heldKeys.begin(), heldKeys.end(), LEFT_ARROW) != heldKeys.end()) xSpeed = -1;
    
    if(std::find(heldKeys.begin(), heldKeys.end(), UP_ARROW) != heldKeys.end()) ySpeed = 1;
    else if(std::find(heldKeys.begin(), heldKeys.end(), DOWN_ARROW) != heldKeys.end()) ySpeed = -1;
    
    
    //change speed when shift is pressed
    if(std::find(heldKeys.begin(), heldKeys.end(), X) != heldKeys.end()){
        xSpeed*=slowMoveSpeed;
        ySpeed*=slowMoveSpeed;
    }
    else{
        xSpeed*=fastMoveSpeed;
        ySpeed*=fastMoveSpeed;
    }
    
    if(xSpeed != 0 && ySpeed != 0){xSpeed /= sqrt(2); ySpeed /= sqrt(2);}
    
    if(pos.x + xSpeed > 0 && pos.x + xSpeed < designResolutionSize.width) pos.x += xSpeed;
    if(pos.y + ySpeed > 0 && pos.y + ySpeed < designResolutionSize.height) pos.y += ySpeed;
    
    this->setPosition(pos);
}

void Player::shot()
{
    if(!aliveFlag) return;
    
    if(std::find(heldKeys.begin(), heldKeys.end(), Z) == heldKeys.end()) return;
    
    auto pos = this->getPosition();
    
    pos.y+=10;
    float angle = 0.5f;
    float angleRate = 0;
    float speed = 20;
    
    pos.x-=10;
    BulletInfo bulletInfo(pos, angle, angleRate, speed, 0 , GRAYCIRCLE);
    auto playerBullet = new PlayerBullet(bulletInfo);
    
    pos.x+=20;
    BulletInfo bulletInfo2(pos, angle, angleRate, speed, 0 , GRAYCIRCLE);
    auto playerBullet2 = new PlayerBullet(bulletInfo2);
    
    Director::getInstance()->getRunningScene()->addChild(playerBullet);
    Director::getInstance()->getRunningScene()->addChild(playerBullet2);
}

void Player::spriteChange()
{
	if (getInvincibleFlag())
	{
		this->playerSprite->setOpacity(255 - this->playerSprite->getOpacity());
		this->colBoxSprite->setOpacity(255 - this->colBoxSprite->getOpacity());
	}
}

void Player::onKeyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    if(keyCode==SHIFT) CCLOG("pressed");
    if(keyCode == ESC){
    }
    else{
        //if(std::find(heldKeys.begin(), heldKeys.end(), keyCode) == heldKeys.end())
            heldKeys.insert(keyCode);
    }
}

void Player::onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    if(keyCode == SHIFT)
    {
        CCLOG("rel");
    }
    if(keyCode == ESC){
        
    }
    else{
        //heldKeys.erase(std::remove(heldKeys.begin(), heldKeys.end(), keyCode), heldKeys.end());
        heldKeys.erase(keyCode);
    }
}

Vec2 Player::getPos() const
{
    return this->getPosition();
}

void Player::setAliveFlag(bool flag)
{
    aliveFlag = flag;
}

bool Player::getAliveFlag() const
{
    return aliveFlag;
}

void Player::getDamage()
{
    setAliveFlag(false);
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("bigexp.mp3");
    
    this->playerSprite->setOpacity(0);
    this->colBoxSprite->setOpacity(0);
}

void Player::rebornReserve(float intervalSeconds)
{
    this->scheduleOnce(schedule_selector(Player::_reborn), intervalSeconds);
}

void Player::invincibleEnd(float dt)
{
    invincibleFlag = false;

	this->playerSprite->setOpacity(255);
	this->colBoxSprite->setOpacity(255);
}

void Player::invincibleStart()
{
    invincibleFlag = true;
}

bool Player::getInvincibleFlag() const
{
    return invincibleFlag;
}

void Player::setInvincibleFlag(bool flag)
{
	invincibleFlag = flag;
}

void Player::_reborn(float t)
{
    setAliveFlag(true);
    invincibleStart();
    
    this->scheduleOnce(schedule_selector(Player::invincibleEnd), rebornInvincibleTimeSeconds);
    this->playerSprite->setOpacity(128);
    this->colBoxSprite->setOpacity(128);
    
    this->setPosition(resolutionWidth/2, 15);
}