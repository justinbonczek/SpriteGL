#include "Transform.hpp"

NS_BEGIN

Vector2 ScreenToWorld(Vector2 v)
{
	return Vector2((v.x / WINDOW_WIDTH) * 2.0f - 1.0f, -((v.y / WINDOW_HEIGHT) * 2.0f - 1.0f));
}

Vector2 WorldToScreen(Vector2 v)
{
	return Vector2(((v.x / 2.0f) + 0.5f) * WINDOW_WIDTH, (((1.0f - v.y) / 2.0f) + 0.5f) * WINDOW_HEIGHT);
}

NS_END