#include "Quaternion.hpp"

Quaternion::Quaternion():
x(0), y(0), z(0), w(0)
{}

Quaternion::Quaternion(float x, float y, float z, float w):
x(x), y(y), z(z), w(w)
{}

Quaternion::Quaternion(Vector3 v, float w) :
x(v.x), y(v.y), z(v.z), w(w)
{}
