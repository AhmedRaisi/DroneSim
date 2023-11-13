#include "drone.h"
#include <cmath>
#include <iostream>
#include "DataCollection.h"
#include <cmath>
using namespace std;

Drone::Drone() {}

Drone::Drone(const std::string& name) : name(name) {
}

Drone::~Drone() {
}

// Updates the drone position and other dynamic properties
void Drone::Update(double dt) {
    // Updates the drone position based on velocity and change in time
    for (int i = 0; i < 3; i++) {
        position[i] = position[i] + speed*dt;
        // Take a picture every 5 seconds with front camera
       time += dt;
       if (time-lastPictureTime > 1) { //changed from 5.0 to 1.0
           cameras[0]->TakePicture();
           lastPictureTime = time;
       }
    }

}

double* Drone::GetPosition()
{
    return position;
}

// Gets the propeller speed.  The index represents the propeller number 0-4.
// Speeds between 0-2 work well, where a speed of 2 is faster than 1.
double Drone::GetPropellerSpeed(int index)
{
    return 0;
}

void Drone::SetJoystick(double x, double y, double z, double rotate)
{
    dir[0] = x; dir[1] = y; dir[2] = z;
}

void Drone::SetVelocity(double* velocity) {
    // Copy the velocity data into the member variable array.
    for(int i=0; i< 3; i++)
    {
        this->velocity[i] = velocity[i];
    }
}


void Drone::Rotate(double angle) {
    // Rotates the drone by changing the velocity by a
    // specified angle.
    double x = velocity[0];
    double y = velocity[1];
    velocity[0] = x*std::cos(angle) - y*std::sin(angle);
    velocity[1] = x*std::sin(angle) + y*std::cos(angle);
}
