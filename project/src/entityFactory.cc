#include "entityFactory.h"

EntityFactory::~EntityFactory(){};
Entity* EntityFactory::CreateEntity() const{
    
}


Drone* DroneFactory::CreateEntity() const
{
    return new Drone("drone");

}



Entity* RobotFactory::CreateEntity() const
{
    return (new Robot("Johnny-Five", 1.0));

}

