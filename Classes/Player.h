//
//  Player.h
//  TestProject
//
//  Created by 이명준 on 2015. 10. 27..
//
//

#ifndef __TestProject__Player__
#define __TestProject__Player__

#include <stdio.h>
#include "Global.h"
#include "PlayerBullet.hpp"

USING_NS_CC;

class Player : public Node
{
public:
    Player(Vec2 pos);
    
    void update(float dt);
    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
    virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
    
    Vec2 getPos() const;
    Vec2 getColBoxPos() const;
    
    void setAliveFlag(bool flag);
    bool getAliveFlag() const;
    
    void invincibleStart();
    void invincibleEnd(float dt);
    bool getInvincibleFlag() const;
	void setInvincibleFlag(bool flag);
    
    void getDamage();
    void rebornReserve(float intervalSeconds);
    
private:
    std::set<EventKeyboard::KeyCode > heldKeys;
    
    Vec2 colBoxPos;
    
    Sprite *playerSprite;
    Sprite *colBoxSprite;
    
    bool aliveFlag;
    bool invincibleFlag;

	float colBoxRadius;
    
    void _reborn(float t);

    void shot();
    void move();
	void spriteChange();
};

#endif /* defined(__TestProject__Player__) */
