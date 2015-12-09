//
//  Bullet.h
//  TestProject
//
//  Created by 이명준 on 2015. 10. 27..
//
//

#ifndef __TestProject__Bullet__
#define __TestProject__Bullet__

#include <stdio.h>
#include "Global.h"
#include "BulletInfo.hpp"

USING_NS_CC;
USING_NS_CC_MATH;

class Bullet : public Node
{
public:
    void update(float dt);
    
    Bullet(const BulletInfo& bulletInfo);
    
    Vec2 getPos() const;
    
    void remove();
    
    float getBulletRadius() const;
	float getDamageParameter() const;
    
protected:
    virtual void move();

    Sprite *bulletSprite;
    
    float angle;
    
    float angleRate;
    
    float speed;
    
    float speedRate;
    
    float bulletRadius;

	float damage;
};

#endif /* defined(__TestProject__Bullet__) */
