//
//  EnemyInfo.hpp
//  TestProject
//
//  Created by 이명준 on 2015. 12. 2..
//
//

#ifndef EnemyInfo_hpp
#define EnemyInfo_hpp

#include <stdio.h>
#include "Global.h"
#include "Shooter.hpp"

class EnemyInfo
{
public:
    EnemyInfo(const int hp,const Vec2 pos, const std::string spriteFileName, Shooter* const shooter);
    EnemyInfo(const int hp,const float x, const float y, const std::string spriteFileName, Shooter* const shooter);
    
    int hp;
    Vec2 pos;
    std::string spriteFileName;
    Shooter* shooter;
};

#endif /* EnemyInfo_hpp */
