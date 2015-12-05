//
//  Shooter.hpp
//  TestProject
//
//  Created by 이명준 on 2015. 12. 1..
//
//

#ifndef Shooter_hpp
#define Shooter_hpp

#include <stdio.h>
#include "Global.h"
#include "ShootInfo.hpp"

class Shooter : public Node
{
public:
    Shooter(const ShootInfo& shootInfo);
    
    virtual void shot() = 0;
    
protected:
    
    Vec2 pos;
    float speed;
    float speedRate;
    float angle;
    float angleRate;
    
    int shootCount;
};

#endif /* Shooter_hpp */
