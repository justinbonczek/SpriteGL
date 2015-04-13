#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "Config.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Rectangle.hpp"

NS_BEGIN

// TODO: Transform Functions
Vector2 ScreenToWorld(Vector2 v);
Vector2 WorldToScreen(Vector2 v);

NS_END

#endif