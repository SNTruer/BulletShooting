//
//  BulletInfo.hpp
//  TestProject
//
//  Created by 이명준 on 2015. 11. 29..
//
//

#ifndef BulletInfo_hpp
#define BulletInfo_hpp

#include <stdio.h>
#include "Global.h"

class BulletInfo
{
public:
    BulletInfo(Vec2 pos, float angle, float angleRate,float speed, float speedRate, const std::string& spriteFileName);
    BulletInfo(float x, float y, float angle, float angleRate,float speed, float speedRate, const std::string& spriteFileName);
    
    Vec2 pos;
    float speed;
    float speedRate;
    float angle;
    float angleRate;
    
    std::string spriteFileName;
};

#endif /* BulletInfo_hpp */
