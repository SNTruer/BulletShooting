//
//  PlayerBullet.hpp
//  TestProject
//
//  Created by 이명준 on 2015. 11. 28..
//
//

#ifndef PlayerBullet_hpp
#define PlayerBullet_hpp

#include <stdio.h>
#include "Global.h"
#include "Bullet.h"

USING_NS_CC;

class PlayerBullet : public Bullet
{
public:
    PlayerBullet(const BulletInfo& bulletInfo);
    
    void update(float dt);
};

#endif /* PlayerBullet_hpp */
