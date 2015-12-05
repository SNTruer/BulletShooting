//
//  EnemyBullet.cpp
//  TestProject
//
//  Created by 이명준 on 2015. 11. 29..
//
//

#include "EnemyBullet.hpp"
#include "WorldManager.hpp"

EnemyBullet::EnemyBullet(const BulletInfo& bulletInfo)
: Bullet(bulletInfo)
{
    auto bulletManager = WorldManager::getInstance()->getBulletManager();
    bulletManager->addBulletPointer(this);
    
    this->schedule(schedule_selector(EnemyBullet::update));
}

void EnemyBullet::update(float dt)
{
    move();
}