//
//  EnemyManager.hpp
//  TestProject
//
//  Created by 이명준 on 2015. 12. 2..
//
//

#ifndef EnemyManager_hpp
#define EnemyManager_hpp

#include <stdio.h>
#include "Global.h"
#include "Enemy.h"
#include "TestEnemy.hpp"

typedef std::map<std::string, Enemy*(*)(EnemyInfo) > EnemyMap;

class EnemyManager : public Node
{
private:
    template<typename T>
    static Enemy* createInstance(EnemyInfo shootInfo){
        return new T(shootInfo);
    }
    
    static EnemyMap createEnemyMap()
    {
        EnemyMap map;
        
        map[TEST_ENEMY] = &createInstance<TestEnemy>;
        
        return map;
    };
    
public:
    
    static const EnemyMap enemyMap;
};


#endif /* EnemyManager_hpp */
