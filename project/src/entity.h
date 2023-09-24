/**
 * @file hysteresis_filter.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */

#ifndef ENTITY_H_
#define ENTITY_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class uses polymorphism in order to create entities.
 *
 */
// Entity is the base class for any simulation object
class Entity {
public:
    /**
    * @brief This entity destructors makes sure that all enititys are deleted.
    *         
    * @return This entity destructor does not return any value.
    */
    virtual ~Entity() {}
    /**
    * @brief returns the name of the entity.
    *         
    * @return returns the name of the entity
    */
    virtual const std::string& GetName();
    /**
    * @brief finds the position of the entity
    *         
    * @return returns the position of the entity
    */
    virtual double* GetPosition() = 0;
    /**
    * @brief finds the length of parameters needed
    *         
    * @return returns the length originally 0 if no entity is found.
    */
    virtual int length() =0;
};


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is a Moveableentity which is a part of the netity clas
 *
 */
class MovableEntity : public Entity {
public:
    /**
    * @brief updates the location of the movable entity
    *         
    * @return update does not return a value
    */
    virtual void Update(double dt) {}
};

#endif