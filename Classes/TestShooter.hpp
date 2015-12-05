//
//  TestShooter.hpp
//  TestProject
//
//  Created by 이명준 on 2015. 12. 1..
//
//

#ifndef TestShooter_hpp
#define TestShooter_hpp

#include <stdio.h>
#include "Shooter.hpp"
#include "Bullet.h"
#include "EnemyBullet.hpp"

class TestShooter : public Shooter
{
public:
    TestShooter(const ShootInfo& shootInfo);
    
    virtual void shot();
};

#endif /* TestShooter_hpp */
