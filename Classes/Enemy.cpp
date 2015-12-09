//
//  Enemy.cpp
//  
//
//  Created by 이명준 on 2015. 11. 1..
//
//

#include "Enemy.h"
#include "WorldManager.hpp"

Enemy::Enemy(const EnemyInfo enemyInfo)
{
    this->hp = enemyInfo.hp;
    this->sprite = Sprite::create(enemyInfo.spriteFileName);
    this->shooter = enemyInfo.shooter;
    
    this->addChild(sprite);
    this->addChild(shooter);

	WorldManager::getInstance()->getEnemyManager()->addEnemyPointer(this);
}

void Enemy::getDamage(float damage)
{
	hp -= damage;
}

void Enemy::remove()
{
	removeFromParent();
	release();
}

float Enemy::getColRadius() const
{
	return colRadius;
}

float Enemy::getHp() const
{
	return hp;
}