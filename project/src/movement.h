#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "web_app.h"
#include <iostream>
#include <vector>
#include "drone.h"

class Movement{
    public:
    virtual ~Movement(){};
    virtual void Move(Drone* drone)=0;
    virtual double* NextPos(double* pos)=0;
};
#endif