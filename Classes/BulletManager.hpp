//
//  BulletManager.hpp
//  TestProject
//
//  Created by 이명준 on 2015. 11. 21..
//
//

#ifndef BulletManager_hpp
#define BulletManager_hpp

#include <stdio.h>
#include "Global.h"
#include "Bullet.h"

USING_NS_CC;

class BulletManager
{
public:
    BulletManager();
    void addBulletPointer(Bullet* const bulletPointer);
    void removeBulletPointer(Bullet* const bulletPointer);
    std::set<Bullet* >* getBulletList();
    size_t getSize();
private:
    std::set<Bullet* > bulletList;
};

#endif /* BulletManager_hpp */
