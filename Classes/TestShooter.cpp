//
//  TestShooter.cpp
//  TestProject
//
//  Created by 이명준 on 2015. 12. 1..
//
//

#include "TestShooter.hpp"
#include "Shooter.hpp"

TestShooter::TestShooter(const ShootInfo shootInfo)
: Shooter(shootInfo)
{
    shootCount = 100;
    angle = 0.0;
    angleRate = 0;
    speed = 5;
}

void TestShooter::shot()
{
    if(shootCount <= 0) return;
    
    BulletInfo bulletInfo(pos, angle, angleRate, speed, 0, GRAYCIRCLE);
    auto bullet = new EnemyBullet(bulletInfo);
    Director::getInstance()->getRunningScene()->addChild(bullet);
    
    BulletInfo bulletInfo2(pos, angle + 0.25f, angleRate, speed, 0, GRAYCIRCLE);
    bullet = new EnemyBullet(bulletInfo2);
    Director::getInstance()->getRunningScene()->addChild(bullet);
    
    BulletInfo bulletInfo3(pos, angle + 0.5f, angleRate, speed, 0, GRAYCIRCLE);
    bullet = new EnemyBullet(bulletInfo3);
    Director::getInstance()->getRunningScene()->addChild(bullet);
    
    BulletInfo bulletInfo4(pos, angle + 0.75f, angleRate, speed, 0, GRAYCIRCLE);
    bullet = new EnemyBullet(bulletInfo4);
    Director::getInstance()->getRunningScene()->addChild(bullet);
    
    angle += 0.2f;
    
    shootCount -= 1;
}