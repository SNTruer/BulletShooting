//
//  ShooterManager.hpp
//  TestProject
//
//  Created by 이명준 on 2015. 12. 1..
//
//

#ifndef ShooterManager_hpp
#define ShooterManager_hpp

#include <stdio.h>
#include "Global.h"
#include "ShootInfo.hpp"
#include "Shooter.hpp"
#include "TestShooter.hpp"

typedef std::map<std::string, Shooter*(*)(ShootInfo) > ShooterMap;

class ShooterManager : public Node
{
private:
    template<typename T>
    static Shooter* createInstance(ShootInfo shootInfo){
        return new T(shootInfo);
    }
    
    static ShooterMap createShooterMap()
    {
        ShooterMap map;
        
        map[TEST_SHOOTER] = &createInstance<TestShooter>;
        
        return map;
    };

public:
    
    static const ShooterMap shooterMap;
};

#endif /* ShooterManager_hpp */
