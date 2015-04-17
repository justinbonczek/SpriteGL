#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Vector.hpp"

struct Rectangle
{
	int x, y;
	uint width, height;

	Rectangle();
	Rectangle(int x, int y, uint width, uint height);
	Rectangle(Vector2 position, Vector2 size);

	// TODO: Finish Rectangle Summaries

	/// <summary>
	/// 
	/// </summary>
	Rectangle Left()const;

	/// <summary>
	/// 
	/// </summary>
	Rectangle Right()const;

	/// <summary>
	/// 
	/// </summary>
	Rectangle Top()const;

	/// <summary>
	/// 
	/// </summary>
	Rectangle Bottom()const;

	/// <summary>
	/// 
	/// </summary>
	Vector2 Position()const;

	/// <summary>
	/// 
	/// </summary>
	Vector2 Size()const;

	/// <summary>
	/// 
	/// </summary>
	Vector2 Center()const;

	/// <summary>
	/// 
	/// </summary>
	bool Contains(Vector2 v);
	
	/// <summary>
	/// 
	/// </summary>
	bool Contains(int x, int y);
	
	/// <summary>
	/// 
	/// </summary>
	bool Contains(float x, float y);
	
	/// <summary>
	/// 
	/// </summary>
	bool Contains(Rectangle r);
	
	/// <summary>
	/// 
	/// </summary>
	void Inflate(int x, int y);
	
	/// <summary>
	/// 
	/// </summary>
	void Inflate(float x, float y);

	/// <summary>
	/// 
	/// </summary>
	bool Intersects(Rectangle r);

	/// <summary>
	/// 
	/// </summary>
	static bool Intersects(Rectangle r1, Rectangle r2);

	/// <summary>
	/// 
	/// </summary>
	void Offset(Vector2 v);
	
	/// <summary>
	/// 
	/// </summary>
	void Offset(int x, int y);
	
	/// <summary>
	/// 
	/// </summary>
	void Offset(float x, float y);

	/// <summary>
	/// 
	/// </summary>
	static Rectangle Union(Rectangle r1, Rectangle r2);
};

#endif