//
//  TestEnemy.hpp
//  TestProject
//
//  Created by 이명준 on 2015. 12. 2..
//
//

#ifndef TestEnemy_hpp
#define TestEnemy_hpp

#include <stdio.h>
#include "Global.h"
#include "Enemy.h"

class TestEnemy : public Enemy
{
public:
    TestEnemy(const EnemyInfo& enemyInfo);
    
    void update(float dt);
    
    virtual void move();
};

#endif /* TestEnemy_hpp */
