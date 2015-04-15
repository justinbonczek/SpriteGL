#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>
#include <vector>

#include "SGLMath.hpp"

#define NS_BEGIN      namespace sgl {
#define NS_END        }
#define WINDOW_WIDTH  1280
#define WINDOW_HEIGHT 720
#define WINDOW_TITLE  "SpriteGL"

typedef unsigned int uint;

Vector2 ScreenToWorld(Vector2 v);
Vector2 WorldToScreen(Vector2 v);

#endif