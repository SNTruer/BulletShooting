//
//  FirstScene.cpp
//  TestProject
//
//  Created by 이명준 on 2015. 10. 21..
//
//

#include "FirstScene.h"
#include "Global.h"
#include "WorldManager.hpp"
#include "BulletManager.hpp"
#include "EnemyBullet.hpp"
#include "ShooterManager.hpp"
#include "TestShooter.hpp"
#include "EnemyManager.hpp"
#include "SimpleAudioEngine.h"

Scene* FirstScene::createScene()
{
    auto scene = Scene::create();

    //auto layer = this->create();
    auto layer = FirstScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool FirstScene::init()
{
    if(!Layer::init()){
        return false;
    }
    
    cnt = 0;
    angle = 0.0;
    angleRate = 0;
    speed = 5;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = CC_CALLBACK_2(FirstScene::onKeyPressed, this);
    keyListener->onKeyReleased = CC_CALLBACK_2(FirstScene::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
    
/*    player = Sprite::create("testbox.png");
    player->setScale(100 / player->getContentSize().width, 100 / player->getContentSize().height);
    player->setPosition(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);*/

	auto background = Sprite::create("space.jpg");
	background->setScale(resolutionWidth / background->getContentSize().width, resolutionHeight / background->getContentSize().height);
	background->setPosition(resolutionWidth / 2, resolutionHeight / 2);
	this->addChild(background);
    
    auto player = new Player(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    auto worldManager = WorldManager::getInstance();
    
    worldManager->setPlayer(player);
    
    this->addChild(player);
    this->addChild(worldManager);
    
    this->schedule(schedule_selector(FirstScene::update));
    
    ShootInfo shootInfo(160, 400, 100);
    auto shooter = ShooterManager::shooterMap.at(TEST_SHOOTER)(shootInfo);
    
    EnemyInfo enemyInfo(100, 160, 400, TEST_ENEMY_SPRITE, shooter);
    auto enemy = EnemyManager::enemyMap.at(TEST_ENEMY)(enemyInfo);
    
    this->addChild(enemy);

	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("BGM.mp3", true);

    //EnemyInfo enemyInfo(10, 160, 400);

    return true;
}

void FirstScene::update(float dt)
{
    if(cnt<100 && sw){
        cnt++;
        
        BulletInfo bulletInfo(160, 400, angle, angleRate, speed, 0, GRAYCIRCLE);
        auto bullet = new EnemyBullet(bulletInfo);
        this->addChild(bullet);
        
        BulletInfo bulletInfo2(160, 400, angle + 0.25f, angleRate, speed, 0, GRAYCIRCLE);
        bullet = new EnemyBullet(bulletInfo2);
        this->addChild(bullet);
        
        BulletInfo bulletInfo3(160, 400, angle + 0.5f, angleRate, speed, 0, GRAYCIRCLE);
        bullet = new EnemyBullet(bulletInfo3);
        this->addChild(bullet);
        
        BulletInfo bulletInfo4(160, 400, angle + 0.75f, angleRate, speed, 0, GRAYCIRCLE);
        bullet = new EnemyBullet(bulletInfo4);
        this->addChild(bullet);

        angle+=0.02f;
        log("hey");
    }
}

void FirstScene::onKeyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    if(keyCode == ESC){
        sw = !sw;
        cnt=0;
    }
    if(std::find(heldKeys.begin(), heldKeys.end(), keyCode) == heldKeys.end())
        heldKeys.push_back(keyCode);
}

void FirstScene::onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    if(keyCode == ESC){
        
    }
    heldKeys.erase(std::remove(heldKeys.begin(), heldKeys.end(), keyCode), heldKeys.end());
}