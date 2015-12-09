//
//  EnemyManager.cpp
//  TestProject
//
//  Created by 이명준 on 2015. 12. 2..
//
//

#include "EnemyManager.hpp"

const EnemyMap EnemyManager::enemyMap = EnemyManager::createEnemyMap();

EnemyManager::~EnemyManager()
{
}

size_t EnemyManager::getSize() const
{
	return enemyList.size();
}

void EnemyManager::addEnemyPointer(Enemy* const enemyPointer)
{
	enemyList.insert(enemyPointer);
}

void EnemyManager::removeEnemyPointer(Enemy* const enemyPointer)
{
	enemyPointer->remove();
	enemyList.erase(enemyPointer);
}

std::set<Enemy* >* EnemyManager::getEnemyList()
{
	return &enemyList;
}