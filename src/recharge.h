#ifndef recharge_H_
#define recharge_H_

#include "entity.h"

// Represents a Tree in a physical system
class Recharge : public Entity {
public:
    // Trees are on the ground, so do not have a z component
    Recharge(const std::string& name, double x, double y) : name(name) {
        pos[0] = x;
        pos[1] = y;
    }
    // Gets the tree name
    const std::string& GetName() { return name; }
    // Gets the tree position
    double* GetPosition() { return pos;}

private:
    double* pos;
    const std::string& name;
};



#endif
