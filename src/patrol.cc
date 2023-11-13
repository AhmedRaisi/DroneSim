#include <string>
#include "patrol.h"
#include "movement.h"
#include "web_app.h"
#include "drone.h"

void Patrol::Move(Drone* drone){
    double* newPos = NextPos(drone->GetPosition());
    if(newPos[1] == -1){
        drone->SetJoystick(0,0,0,0);  // stop drone
    }
    else if(drone->GetPosition()[0] < newPos[0]){
        drone->SetJoystick(1,0,0,0);   // front
    }
    else if(drone->GetPosition()[2] < newPos[2]){
        drone->SetJoystick(0,0,1,0);  // right
    }
    else if(drone->GetPosition()[0] > newPos[0]){
        drone->SetJoystick(-1,0,0,0);  // down
    }
    else if(drone->GetPosition()[2] > newPos[2]){
        drone->SetJoystick(0,0,-1,0);  // left
    }
}

double* Patrol::NextPos(double* pos){
    double min[3] = {-1450,264,-900};
    double max[3] = {1550,264,900};
    static double newPos[3];
    //loop1
    if(pos[0] >= -100 && pos[2] >= 60){ // go down (corner)
        newPos[0] = -100;
        newPos[1] = pos[1];
        newPos[2] = pos[2];
    }
    else if(pos[0] < -100 && pos[2] >= 40){ // go left
        newPos[0] = pos[0];
        newPos[1] = pos[2];
        newPos[2] = 40;
    }
    else if(pos[0] < 109 && pos[2] < 40 && pos[2]>20){ // go forward again
        newPos[0] = 109;
        newPos[1] = pos[1];
        newPos[2] = pos[2];
    }
    else if(pos[0] >= 109 && pos[2] >= 20){ // go left
        newPos[0] = pos[0];
        newPos[1] = pos[1];
        newPos[2] = 20;
    }


    //loop2


    else if(pos[0] >= -101 && pos[2] >= 19){ // go down 
        newPos[0] = -101;
        newPos[1] = pos[1];
        newPos[2] = pos[2];
    }
    else if(pos[0] < -99 && pos[2] >= 0){ // go left
        newPos[0] = pos[0];
        newPos[1] = pos[2];
        newPos[2] = 0;
    }
    else if(pos[0] < 108 && pos[2] < 0 && pos[2]>-20){ // go forward again
        newPos[0] = 108;
        newPos[1] = pos[1];
        newPos[2] = pos[2];
    }
    else if(pos[0] >= 108 && pos[2] >= -20){ // go left
        newPos[0] = pos[0];
        newPos[1] = pos[1];
        newPos[2] = -20;
    }


    //loop3


    else if(pos[0] >= -102 && pos[2] >= -21){ // go down 
        newPos[0] = -102;
        newPos[1] = pos[1];
        newPos[2] = pos[2];
    }
    else if(pos[0] < -101 && pos[2] >= -40){ // go left
        newPos[0] = pos[0];
        newPos[1] = pos[2];
        newPos[2] = -40;
    }
    else if(pos[0] < 107 && pos[2] < -40 && pos[2]>-60){ // go forward again
        newPos[0] = 107;
        newPos[1] = pos[1];
        newPos[2] = pos[2];
    }
    else if(pos[0] >= 107 && pos[2] >= -60){ // go left
        newPos[0] = pos[0];
        newPos[1] = pos[1];
        newPos[2] = -60;
    }

    // //cleanup: go down then stop

    else if(pos[0] >= -103 && pos[2] >= -61){ // go down 
        newPos[0] = -103;
        newPos[1] = pos[1];
        newPos[2] = pos[2];
    }
    else{ // STOP
        newPos[0] = pos[0];
        newPos[1] = -1;
        newPos[2] = pos[2];
    }
    return newPos;
}
