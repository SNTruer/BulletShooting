//
//  ShootInfo.cpp
//  TestProject
//
//  Created by 이명준 on 2015. 12. 1..
//
//

#include "ShootInfo.hpp"

ShootInfo::ShootInfo(Vec2 pos, int shootCount)
: pos(pos), shootCount(shootCount)
{
    
}

ShootInfo::ShootInfo(float x, float y, int shootCount)
: pos(Vec2(x, y)), shootCount(shootCount)
{
    
}