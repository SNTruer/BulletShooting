//
//  PlayerBullet.cpp
//  TestProject
//
//  Created by 이명준 on 2015. 11. 28..
//
//

#include "PlayerBullet.hpp"
#include "WorldManager.hpp"

PlayerBullet::PlayerBullet(const BulletInfo& bulletInfo)
: Bullet(bulletInfo)
{
    auto playerBulletManager = WorldManager::getInstance()->getPlayerBulletManager();
    playerBulletManager->addBulletPointer(this);
	this->damage = 1.0f;
    
    this->schedule(schedule_selector(PlayerBullet::update));
}

void PlayerBullet::update(float dt)
{
    move();
}
