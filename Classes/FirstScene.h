//
//  FirstScene.h
//  TestProject
//
//  Created by 이명준 on 2015. 10. 21..
//
//

#ifndef __TestProject__FirstScene__
#define __TestProject__FirstScene__

#include <stdio.h>
#include "Player.h"
#include "Bullet.h"

USING_NS_CC;

class FirstScene : public cocos2d::Layer
{
public:
    static Scene* createScene();
    
    virtual bool init();
    
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);
    void update(float dt);
    
    Sprite* player;
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(FirstScene);
    
private:
    std::vector<EventKeyboard::KeyCode > heldKeys;
    
    int cnt;
    float angle;
    float angleRate;
    float speed;
    int sw;

	Sprite* background1;
	Sprite* background2;

	void backgroundMove();
};
#endif /* defined(__TestProject__FirstScene__) */