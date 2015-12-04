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
    
    
    this->schedule(schedule_selector(WorldManager::update));
}

WorldManager::WorldManager(Player*& player){
    bulletManager = new BulletManager();
    this->player = player;
    
    this->schedule(schedule_selector(WorldManager::update));
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

void WorldManager::update(float dt)
{
    bulletCheck();
}

bool WorldManager::posCheck(const Vec2 bulletPos)
{
    return (bulletPos.x<-50 || bulletPos.x>resolutionWidth+50 || bulletPos.y<-50 || bulletPos.y>resolutionHeight+50) ? true : false;
}

bool WorldManager::colCheck(const Vec2 playerPos,const Vec2 bulletPos, const float bulletRadius)
{
    return ((playerPos.x - bulletPos.x)*(playerPos.x - bulletPos.x) + (playerPos.y - bulletPos.y)*(playerPos.y - bulletPos.y) < (colBoxRadius + bulletRadius)*(colBoxRadius + bulletRadius)) ? true : false;
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
    
    for(auto bIt = playerBulletList->begin(); bIt != playerBulletList->end();){
        auto bulletPos = (*bIt)->getPos();
        auto bulletRadius = (*bIt)->getBulletRadius();
        
        if(posCheck(bulletPos)){
            playerBulletManager->removeBulletPointer((*bIt++));
            continue;
        }
        
        if(*bIt==NULL) break;
        
        //bulletCollision with enemy event
        
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

void WorldManager::gameOver()
{
    
}