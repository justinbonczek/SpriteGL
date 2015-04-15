#include "Rectangle.hpp"

Rectangle::Rectangle():
x(0), y(0), width(0), height(0)
{}
Rectangle::Rectangle(int x, int y, uint width, uint height):
x(x), y(y), width(width), height(height)
{}
Rectangle::Rectangle(Vector2 position, Vector2 size):
x((int)position.x), y((int)position.y), width((uint)size.x), height((uint)size.y)
{}

int Rectangle::Left()const { return x; }
int Rectangle::Right()const { return x + width; }
int Rectangle::Top()const { return y; }
int Rectangle::Bottom()const { return y + width; }
Vector2 Rectangle::Position()const { return Vector2((float)x, (float)y); }
Vector2 Rectangle::Size()const { return Vector2((float)width, (float)height); }
Vector2 Rectangle::Center()const { return Vector2(x + width / 2.0f, y + height / 2.0f); }

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