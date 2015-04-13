#include "Rectangle.hpp"

NS_BEGIN

Rectangle::Rectangle()
{}
Rectangle::Rectangle(int x, int y, uint width, uint height):
x(x), y(y), width(width), height(height)
{}
Rectangle::Rectangle(Vector2 position, Vector2 size):
x((int)position.x), y((int)position.y), width((uint)size.x), height((uint)size.y)
{}

int Rectangle::Left() { return x; }
int Rectangle::Right() { return x + width; }
int Rectangle::Top() { return y; }
int Rectangle::Bottom() { return y + width; }
Vector2 Rectangle::Position() { return Vector2((float)x, (float)y); }
Vector2 Rectangle::Size() { return Vector2((float)width, (float)height); }
Vector2 Rectangle::Center() { return Vector2(x + width / 2.0f, y + height / 2.0f); }

bool Rectangle::Contains(Vector2 v) { return ((((x <= v.x) && (v.x < (x + width))) && ((y <= v.y)) && (v.y < (y + height)))); }
// TODO: Finish Rectangle Functions
//bool Rectangle::Contains(int x, int y){}
//bool Rectangle::Contains(float x, float y){}
//bool Rectangle::Contains(Rectangle r){}
//
//void Rectangle::Inflate(int x, int y){}
//void Rectangle::Inflate(float x, float y){}
//
//bool Rectangle::Intersects(Rectangle r){}
//bool Rectangle::Intersects(Rectangle r1, Rectangle r2){}
//
//void Rectangle::Offset(Vector2 v){}
//void Rectangle::Offset(int x, int y){}
//void Rectangle::Offset(float x, float y){}
//
//Rectangle Rectangle::Union(Rectangle r1, Rectangle r2){}
//
NS_END