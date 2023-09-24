#ifndef PATROL_H
#define PATROL_H
#include "movement.h"
#include "web_app.h"
#include <iostream>
#include <vector>
#include "drone.h"

class Patrol : public Movement{
public:
    void Move(Drone* drone) override;
    double* NextPos(double* pos) override;
};
#endif