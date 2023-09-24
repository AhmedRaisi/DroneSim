/**
 * @file hysteresis_filter.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */

#ifndef DRONE_H_
#define DRONE_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include "entity.h"
#include "camera.h"
#include "DataCollection.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class is the Image class which contains the main methods to modify or creat an image.
 *
 */

// A drone object that has a position and propellers
class Drone : public MovableEntity {

public:
    // Default Constructor
    /**
    * @brief Drone constructor without parameters
    *         
    * @return This Drone does not return any value.
    */
    Drone();
    /**
    * @brief This Drone constructor takes one argument and it creates an named drone.
    *         
    * @return This Image function does not return any value.
    */
    Drone(const std::string& name);
    /**
    * @brief This is a destructor that deletes the drone from the memory.
    *         
    * @return The drone destructor does not return any value.
    */
    ~Drone();
    /**
    * @brief Updates the drone parameters.
    *         
    * @return The update does not return any value.
    */
    void Update(double dt);
    /**
    * @brief gets position value from drone.
    *         
    * @return returns the positions value.
    */
    double* GetPosition();
    /**
    * @brief Updates joystick to update the direction of the drone
    *         
    * @return setjoystick does not return a value.
    */
    void SetJoystick(double x, double y, double z, double rotate);
    /**
    * @brief gives the speed of the propeller on the drone depending on the index
    *         
    * @return returns the speed of the propeller
    */
    double GetPropellerSpeed(int index);
    /**
    * @brief Returns the name of the drone based on the name variable
    *         
    * @return the name of the drone 
    */
    const std::string& GetName() { return name; }
    /**
    * @brief sets the velocity of the drone 
    *         
    * @return does not return anything.
    */
    void SetVelocity(double* velocity);
    /**
    * @brief rotate the drone based on the angle specified
    *         
    * @return does not return anything.
    */
    void Rotate(double angle);
    /**
    * @brief length in order to understand the parameters needed for this entity.
    *         
    * @return returns 3
    */
    int length() { return 3;}
    Drone(const Drone& drone) = delete;
    Drone& operator=(const Drone& drone) = delete;

    int id;
    std::string name;
    double position[3];
    double* velocity;
    double dir[3];
    double speed;
    std::vector<Camera*> cameras;
    float lastPictureTime = 0.0;
    float time = 0.0;

};
#endif



