#ifndef ENTITYFACTORY_H_
#define ENTITYFACTORY_H_

#include "entity.h"
#include "drone.h"
#include "robot.h"
#include "hospital.h"
#include "recharge.h"
#include <iostream>

class EntityFactory 
{
    public:
        virtual ~EntityFactory();
        virtual Entity* CreateEntity() const;

        //Entity Create() const;

};

class DroneFactory: public EntityFactory
{
    public:

        Drone* CreateEntity() const override;
};


class RobotFactory: public EntityFactory
{
    public:

        Entity* CreateEntity() const override;
};
#endif