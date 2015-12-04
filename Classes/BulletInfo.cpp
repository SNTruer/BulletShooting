//
//  BulletInfo.cpp
//  TestProject
//
//  Created by 이명준 on 2015. 11. 29..
//
//

#include "BulletInfo.hpp"

BulletInfo::BulletInfo(Vec2 pos, float angle, float angleRate,float speed, float speedRate, const std::string& spriteFileName)
: pos(pos), speed(speed), speedRate(speedRate), angle(angle), angleRate(angleRate), spriteFileName(spriteFileName)
{
}

BulletInfo::BulletInfo(float x,float y, float angle, float angleRate,float speed, float speedRate, const std::string& spriteFileName)
: pos(Vec2(x, y)), speed(speed), speedRate(speedRate), angle(angle), angleRate(angleRate), spriteFileName(spriteFileName)
{
}