//
//  Global.h
//  TestProject
//
//  Created by 이명준 on 2015. 10. 21..
//
//

#ifndef TestProject_Global_h
#define TestProject_Global_h

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

const EventKeyboard::KeyCode RIGHT_ARROW = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
const EventKeyboard::KeyCode LEFT_ARROW = EventKeyboard::KeyCode::KEY_LEFT_ARROW;
const EventKeyboard::KeyCode UP_ARROW = EventKeyboard::KeyCode::KEY_UP_ARROW;
const EventKeyboard::KeyCode DOWN_ARROW = EventKeyboard::KeyCode::KEY_DOWN_ARROW;
const EventKeyboard::KeyCode ESC = EventKeyboard::KeyCode::KEY_ESCAPE;
const EventKeyboard::KeyCode SHIFT = EventKeyboard::KeyCode::KEY_SHIFT;
const EventKeyboard::KeyCode Z = EventKeyboard::KeyCode::KEY_Z;
const EventKeyboard::KeyCode X = EventKeyboard::KeyCode::KEY_X;

const cocos2d::Size designResolutionSize = cocos2d::Size(320, 480);
const cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
const cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
const cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

const float fastMoveSpeed = 6;
const float slowMoveSpeed = 2;

const size_t resolutionWidth = designResolutionSize.width;
const size_t resolutionHeight = designResolutionSize.height;

const float PLAYER_COL_BOX_RADIUS = 2.5f;
const float playerSizeWidth = 20.0f;
const float playerSizeHeight = 30.0f;

const float normalBulletRadius = 5.0f;

const float rebornIntervalSeconds = 1.5f;
const float rebornInvincibleTimeSeconds = 3.0f;

const std::string TEST_ENEMY = "TEST_ENEMY";
const std::string TEST_ENEMY_SPRITE = "HelloWorld.png";
const float TEST_ENEMY_COL_RADIUS = 15;

const std::string GRAYCIRCLE = "graycircle.png";
const std::string DEFAULT_SHOOTER = "DEFAULT_SHOOTER";
const std::string TEST_SHOOTER = "TEST_SHOOTER";

#endif
