//
//  WorldManager.hpp
//  TestProject
//
//  Created by 이명준 on 2015. 11. 21..
//
//

#ifndef WorldManager_hpp
#define WorldManager_hpp

#include <stdio.h>
#include "Player.h"
#include "Global.h"
#include "Bullet.h"
#include "BulletManager.hpp"
#include "EnemyManager.hpp"

USING_NS_CC;
USING_NS_CC_MATH;

class WorldManager : public Node
{
public:
    void setPlayer(Player*& player);
    BulletManager* getBulletManager();
    BulletManager* getPlayerBulletManager();
	EnemyManager* getEnemyManager();
    virtual void update(float dt);
    
    static WorldManager* getInstance(){
        if(!singleton) singleton = new WorldManager();
            
        return singleton;
    };
private:
    WorldManager();
	~WorldManager();
    
    static WorldManager* singleton;
    
    BulletManager* bulletManager;
    BulletManager* playerBulletManager;
	EnemyManager* enemyManager;
    Player* player;

    void collisionPlayer();
	bool collisionEnemy(Enemy* enemy, float damage);

    void bulletCheck();
	void enemyCheck();
    
    //void bulletWorldOut();
    inline bool posCheck(const Vec2 bulletPos);
    inline bool colCheck(const Vec2 playerPos, const Vec2 bulletPos, const float bulletRadius);
	inline bool colCheck(const Vec2 aPos, const float aColBoxRadius, const Vec2 bPos, const float bColBoxRadius);
    
    unsigned int playerLifeCount;
    unsigned int playerBombCount;
    float playerPower;
    
    void gameOver();
};

#endif /* WorldManager_hpp */
