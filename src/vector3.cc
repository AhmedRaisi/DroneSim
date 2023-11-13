#include "vector3.h"

#include <iostream>
using namespace std;

Vector3::Vector3(float xVal, float yVal, float zVal)
	: x(xVal), y(yVal), z(zVal) { }

Vector3::Vector3() {x = 0; y = 0; z = 0;}

void Vector3::Print()
{
	cout << "[" << x << ", " << y << ", " << z<< "]\n";

}



Vector3 Vector3::operator+(Vector3 val) 
{
	return Vector3(x+val.x, y+val.y, z+val.z);
}

Vector3 Vector3::operator-(Vector3 val)
{       
        return Vector3(x-val.x, y-val.y, z-val.z);
}

Vector3 Vector3::operator*(float val)
{       
        return Vector3(x*val, y*val, z*val);
} 

Vector3 Vector3::operator/(float val)
{       
        return Vector3(x/val, y/val, z/val);
}  

bool Vector3::operator==(Vector3 val)
{       
        return x== val.x && y== val.y  && z== val.z ;
}  

