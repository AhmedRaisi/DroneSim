// #ifndef BEELINE_H_
// #define BEELINE_H_

// #include "web_app.cc.h"
// #include <iostream>
// #include "vetor3.h"



// namespace csci3081 {

//     class Beeline{

//         public:  
//             int id; double pos[3]; double dir[3];double robot[3]; double speed;
//             double norm[3]; 
//             // Default Constructor
//             Beeline();

//             Beeline(double loc1x,double loc1y, double loc1z, double loc2x,double loc2y, double loc2z){dronex = loc1x; droney = loc1y; dronez = loc1z; robotx = loc2x; roboty = loc2y; robotz = loc3z};
//             // Updates the drone position and other dynamic properties
//             void Update(double dt);
//             // Gets the drone position.  Index represents the 3D spatial component 
//             // (e.g. index = 0 means the x value)
//             double GetPosition(int index);
//             // Gets the propeller speed.  The index represents the propeller number 0-4.
//             // Speeds between 0-2 work well, where a speed of 2 is faster than 1.
//             double GetPropellerSpeed(int index);
//             // Sets the direction of the joystick.  For example x = 1, means move in the positive x direction and
//             // x = -1 means move in the negative x direction. 
//             void SetJoystick(double x, double y, double z, double rotate);

//             // void FindDirection(double loc1x,double loc1y, double loc1z, double loc2x,double loc2y, double loc2z);
//             void FindDirection();

//             void NormDirection();

//             // double DisTraveled(double direction, double dt );

//             // double MoveDrone(double distance, double direction);


        
//         private:
//             Vector3 velocity;









//     };

// }

// #endif

