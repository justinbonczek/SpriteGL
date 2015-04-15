#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include "Vector.hpp"

// TODO: Implement Quaternions

struct Quaternion
{
	float x, y, z, w;

	Quaternion();
	Quaternion(float x, float y, float z, float w);
	Quaternion(Vector3 v, float w);
	
};

#endif