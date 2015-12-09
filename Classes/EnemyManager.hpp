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

typedef std::map<std::string, Enemy*(*)(const EnemyInfo&) > EnemyMap;

class EnemyManager : public Node
{
private:
    template<typename T>
    static Enemy* createInstance(const EnemyInfo& shootInfo){
        return new T(shootInfo);
    }
    
    static EnemyMap createEnemyMap()
    {
        EnemyMap map;
        
        map[TEST_ENEMY] = &createInstance<TestEnemy>;
        
        return map;
    };

	std::set<Enemy* > enemyList;
    
public:

	~EnemyManager();
    
    static const EnemyMap enemyMap;

	size_t getSize() const;

	std::set<Enemy*>* getEnemyList();

	void addEnemyPointer(Enemy* const enemyPointer);
	void removeEnemyPointer(Enemy* const enemyPointer);
};


#endif /* EnemyManager_hpp */
