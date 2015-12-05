//
//  BulletManager.cpp
//  TestProject
//
//  Created by 이명준 on 2015. 11. 21..
//
//

#include "BulletManager.hpp"

BulletManager::BulletManager(){
}

void BulletManager::addBulletPointer(Bullet* const bulletPointer){
    bulletList.insert(bulletPointer);
}

void BulletManager::removeBulletPointer(Bullet* const bulletPointer){
    bulletPointer->remove();
    bulletList.erase(bulletPointer);
}

size_t BulletManager::getSize(){
    return bulletList.size();
}

std::set<Bullet* >* BulletManager::getBulletList(){
    return &bulletList;
}