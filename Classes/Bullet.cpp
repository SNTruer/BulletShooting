//
//  Bullet.cpp
//  TestProject
//
//  Created by 이명준 on 2015. 10. 27..
//
//

#include "Bullet.h"
#include "WorldManager.hpp"

Bullet::Bullet(const BulletInfo& bulletInfo)
{
    this->angle = bulletInfo.angle * 360 + 90;
    this->angleRate = bulletInfo.angleRate;
    this->speed = bulletInfo.speed;
    this->speedRate = bulletInfo.speedRate;
    
    bulletSprite = Sprite::create(bulletInfo.spriteFileName);
    bulletSprite->setScale(normalBulletRadius*2/bulletSprite->getContentSize().width, normalBulletRadius*2/bulletSprite->getContentSize().height);
    
    bulletRadius = normalBulletRadius;
    
    this->setPosition(bulletInfo.pos);
    
    this->addChild(bulletSprite);
}

void Bullet::remove(){
    removeFromParent();
    release();
}

void Bullet::update(float dt)
{
    move();
}

void Bullet::move()
{
    auto position = this->getPosition();
    float rad = CC_DEGREES_TO_RADIANS(angle);
    
    position.x += speed*cosf(rad);
    position.y -= speed*sinf(rad);
    
    angle += angleRate;
    speed += speedRate;
    
    this->setPosition(position);
}

Vec2 Bullet::getPos() const
{
    return getPosition();
}

float Bullet::getBulletRadius() const
{
    return bulletRadius;
}