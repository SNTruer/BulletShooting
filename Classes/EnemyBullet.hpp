//
//  EnemyBullet.hpp
//  TestProject
//
//  Created by 이명준 on 2015. 11. 29..
//
//

#ifndef EnemyBullet_hpp
#define EnemyBullet_hpp

#include <stdio.h>
#include "Global.h"
#include "Bullet.h"

USING_NS_CC;

class EnemyBullet : public Bullet
{
public:
    EnemyBullet(const BulletInfo& bulletInfo);
    
    void update(float dt);
};

#endif /* EnemyBullet_hpp */
