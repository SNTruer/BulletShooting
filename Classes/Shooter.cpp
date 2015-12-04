//
//  Shooter.cpp
//  TestProject
//
//  Created by 이명준 on 2015. 12. 1..
//
//

#include "Shooter.hpp"

Shooter::Shooter(const ShootInfo shootInfo)
{
    this->pos = shootInfo.pos;
    this->shootCount = shootInfo.shootCount;
}