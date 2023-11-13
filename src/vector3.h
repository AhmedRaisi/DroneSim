#ifndef vector_h
#define vector_h

#include <string>
#include <cmath>
using namespace std;

struct Vector3 
{
	public:
		Vector3(float x, float y, float z);
		Vector3();

		void Print();
		Vector3 operator+(Vector3 val);
		Vector3 operator-(Vector3 val);
		Vector3 operator*(float val);
		Vector3 operator/(float val);
		bool operator==(Vector3 val);
	private:
		float x,y,z;
};
#endif