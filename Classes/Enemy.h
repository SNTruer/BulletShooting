//
//  Enemy.h
//  
//
//  Created by 이명준 on 2015. 11. 1..
//
//

#ifndef ____Enemy__
#define ____Enemy__

#include <stdio.h>
#include "Shooter.hpp"
#include "EnemyInfo.hpp"
#include "ShooterManager.hpp"
USING_NS_CC;

class Enemy : public Node
{
public:
    Enemy(const EnemyInfo enemyInfo);
    
    virtual void move() = 0;
    
protected:
    
    int hp;
    Sprite* sprite;
    Shooter* shooter;
};

#endif /* defined(____Enemy__) */