// #include "beeline.h"
// #include "web_app.cc.h"
// #include <math.h>
// #include <iostream>


// using namespace csci3081;

// Beeline::Beeline(){
    
// }
//     // Updates the drone position and other dynamic properties
//     void Beeline::Update(double dt){
//         FindDirection();
//         NormDirection();
//         for (int i = 0; i < 3; i++) {
//            pos[i] += speed*dir[i]*dt;
//        }

//     }
//     // Gets the drone position.  Index represents the 3D spatial component 
//     // (e.g. index = 0 means the x value)
//     double Beeline::GetPosition(int index){
//         return 0;
//     }
//     // Gets the propeller speed.  The index represents the propeller number 0-4.
//     // Speeds between 0-2 work well, where a speed of 2 is faster than 1.
//     double Beeline::GetPropellerSpeed(int index){
//         return 0;
//     }
//     // Sets the direction of the joystick.  For example x = 1, means move in the positive x direction and
//     // x = -1 means move in the negative x direction. 
//     void Beeline::SetJoystick(double x, double y, double z, double rotate){

//         // std::cout << x << " " << y << " " << z << " " << std::endl;
//         dir[0] = x; dir[1] = y; dir[2] = z;
        
//     }
//     void Beeline::FindDirection(){

//         // double d[3];
//         // double robot[3];

//         for (int i = 0; i < 3; i++) {
//            dir[i] = robot[i] - pos[i];
//         }
//     }

//     void Beeline::NormDirection(){
//         double mag = sqrt((dir[0]*dir[0])+(dir[1]*dir[1])+(dir[2]*dir[2]))
//         for (int i = 0; i < 3; i++) {
//         //    norm[i] = dir[i] / mag;
//             dir[i] = dir[i] / mag;
//         }
//     }

//     // double Beeline::DisTraveled(double direction, double dt ){

//     //     return 0;

//     // }

//     // double Beeline::MoveDrone(double distance, double direction){
//     //     return 0;

//     // }

