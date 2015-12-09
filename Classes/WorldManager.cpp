//
//  WorldManager.cpp
//  TestProject
//
//  Created by 이명준 on 2015. 11. 21..
//
//

#include "WorldManager.hpp"
#define COCOS2D_DEBUG 1


WorldManager* WorldManager::singleton = NULL;

WorldManager::WorldManager(){
    bulletManager = new BulletManager();
    playerBulletManager = new BulletManager();
	enemyManager = new EnemyManager();
    
    this->schedule(schedule_selector(WorldManager::update));
}

WorldManager::~WorldManager() {
	delete bulletManager;
	delete playerBulletManager;
	delete enemyManager;

	this->unschedule(schedule_selector(WorldManager::update));
}

void WorldManager::setPlayer(Player*& player){
    this->player = player;
}

BulletManager* WorldManager::getBulletManager(){
    return bulletManager;
}

BulletManager* WorldManager::getPlayerBulletManager()
{
    return playerBulletManager;
}

EnemyManager* WorldManager::getEnemyManager()
{
	return enemyManager;
}

void WorldManager::update(float dt)
{
    bulletCheck();
	enemyCheck();
}

bool WorldManager::posCheck(const Vec2 bulletPos)
{
    return (bulletPos.x<-50 || bulletPos.x>resolutionWidth+50 || bulletPos.y<-50 || bulletPos.y>resolutionHeight+50) ? true : false;
}

bool WorldManager::colCheck(const Vec2 playerPos,const Vec2 bulletPos, const float bulletRadius)
{
    return ((playerPos.x - bulletPos.x)*(playerPos.x - bulletPos.x) + (playerPos.y - bulletPos.y)*(playerPos.y - bulletPos.y) < (PLAYER_COL_BOX_RADIUS + bulletRadius)*(PLAYER_COL_BOX_RADIUS + bulletRadius)) ? true : false;
}

bool WorldManager::colCheck(const Vec2 aPos, const float aColBoxRadius, const Vec2 bPos, const float bColBoxRadius)
{
	return ((aPos.x - bPos.x)*(aPos.x - bPos.x) + (aPos.y - bPos.y)*(aPos.y - bPos.y) <
		(aColBoxRadius + bColBoxRadius)*(aColBoxRadius + bColBoxRadius)) ? true : false;
}

void WorldManager::enemyCheck()
{
	auto enemyList = enemyManager->getEnemyList();

	for (auto eIt = enemyList->begin(); eIt != enemyList->end();) {
		auto enemyPos = (*eIt)->getPosition();
		auto enemyColRadius = (*eIt)->getColRadius();

		if (player != NULL && colCheck(player->getPos(), enemyPos, enemyColRadius)) {
			collisionPlayer();
		}

		eIt++;
	}
}

void WorldManager::bulletCheck()
{
    auto bulletList = bulletManager->getBulletList();
    
    for(auto bIt = bulletList->begin(); bIt != bulletList->end();){
        auto bulletPos = (*bIt)->getPos();
        auto bulletRadius = (*bIt)->getBulletRadius();
        
        if(posCheck(bulletPos)){
            bulletManager->removeBulletPointer((*bIt++));
            continue;
        }
        
        if(*bIt==NULL) break;
        
        if(player!=NULL && colCheck(player->getPos(), bulletPos, bulletRadius)){
            collisionPlayer();
        }
        
        if(*bIt==NULL) break;
        bIt++;
    }
    
    auto playerBulletList = playerBulletManager->getBulletList();
	auto enemyList = enemyManager->getEnemyList();
    
    for(auto bIt = playerBulletList->begin(); bIt != playerBulletList->end();){
        auto bulletPos = (*bIt)->getPos();
        auto bulletRadius = (*bIt)->getBulletRadius();
        
        if(posCheck(bulletPos)){
            playerBulletManager->removeBulletPointer((*bIt++));
            continue;
        }
        
        if(*bIt==NULL) break;
        
        //bulletCollision with enemy event
		for (auto eIt = enemyList->begin(); eIt != enemyList->end();) {
			auto enemyPos = (*eIt)->getPosition();
			auto enemyColRadius = (*eIt)->getColRadius();

			if (colCheck(bulletPos,bulletRadius, enemyPos, enemyColRadius)) {
				if(collisionEnemy(*(eIt++), (*bIt)->getDamageParameter())) continue;
			}
			else eIt++;
		}
        
        if(*bIt==NULL) break;
        bIt++;
    }
}

void WorldManager::collisionPlayer()
{
    if(player == NULL) return;
    
    if(!player->getAliveFlag()) return;
    
    if(player->getInvincibleFlag()) return;
    
    player->getDamage();
    
    playerLifeCount--;
    
    if(playerLifeCount>0) player->rebornReserve(rebornIntervalSeconds);
    else gameOver();
}

bool WorldManager::collisionEnemy(Enemy* enemy, float damage)
{
	enemy->getDamage(damage);

	if (enemy->getHp() < 0)
	{
		enemyManager->removeEnemyPointer(enemy);
		return true;
	}

	return false;
}

void WorldManager::gameOver()
{
    
}