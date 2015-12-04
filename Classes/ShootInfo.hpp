//
//  ShootInfo.hpp
//  TestProject
//
//  Created by 이명준 on 2015. 12. 1..
//
//

#ifndef ShootInfo_hpp
#define ShootInfo_hpp

#include <stdio.h>
#include "Global.h"

class ShootInfo
{
public:
    ShootInfo(Vec2 pos, int shootCount);
    ShootInfo(float x, float y, int shootCount);
    
    Vec2 pos;
    int shootCount;
};

#endif /* ShootInfo_hpp */
