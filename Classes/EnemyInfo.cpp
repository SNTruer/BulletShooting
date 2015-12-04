//
//  EnemyInfo.cpp
//  TestProject
//
//  Created by 이명준 on 2015. 12. 2..
//
//

#include "EnemyInfo.hpp"

EnemyInfo::EnemyInfo(const int hp, const Vec2 pos, const std::string spriteFileName, Shooter* const shooter)
: hp(hp), pos(pos), spriteFileName(spriteFileName), shooter(shooter)
{
}

EnemyInfo::EnemyInfo(const int hp,const float x, const float y, const std::string spriteFileName, Shooter* const shooter)
: hp(hp), pos(Vec2(x, y)), spriteFileName(spriteFileName), shooter(shooter)
{
    
}