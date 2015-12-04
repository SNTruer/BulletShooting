//
//  Enemy.cpp
//  
//
//  Created by 이명준 on 2015. 11. 1..
//
//

#include "Enemy.h"

Enemy::Enemy(const EnemyInfo enemyInfo)
{
    this->hp = enemyInfo.hp;
    this->sprite = Sprite::create(enemyInfo.spriteFileName);
    this->shooter = enemyInfo.shooter;
    
    this->addChild(sprite);
    this->addChild(shooter);
}
