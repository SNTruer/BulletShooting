//
//  TestEnemy.cpp
//  TestProject
//
//  Created by 이명준 on 2015. 12. 2..
//
//

#include "TestEnemy.hpp"

TestEnemy::TestEnemy(const EnemyInfo& enemyInfo)
: Enemy(enemyInfo)
{
    this->setPosition(enemyInfo.pos);
    this->sprite->setScale(15 / this->sprite->getContentSize().width, 10 / this->sprite->getContentSize().height);
    
    this->schedule(schedule_selector(TestEnemy::update));
}

void TestEnemy::update(float dt)
{
    shooter->shot();
}

void TestEnemy::move()
{
    
}