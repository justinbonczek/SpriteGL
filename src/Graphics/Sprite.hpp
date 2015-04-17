#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "..\Config.hpp"
#include "Texture.hpp"
#include "Shader.hpp"

NS_BEGIN

class Sprite
{
public:
	Sprite();
	~Sprite();
	
	/// <summary>
	/// Updates the sprite
	/// </summary>
	virtual void Update(float dt);

	/// <summary>
	/// Renders the sprite to the screen
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// Translate the sprite by given x and y values
	/// </summary>
	template<typename T>
	void Translate(T x, T y);

	/// <summary>
	/// Translate the sprite by given translation vector
	/// </summary>
	void Translate(Vector2 translation);

	/// <summary>
	/// Scale the sprite by given x and y values
	/// </summary>
	template<typename T>
	void Scale(T x, T y);

	/// <summary>
	/// Scale the sprite by given scale vector
	/// </summary>
	void Scale(Vector2 scale);

	/// <summary>
	/// Rotate the sprite by given angle in degrees
	/// </summary>
	void Rotate(float angle);

	/// <summary>
	/// Sets the sprite's shader to the given shader
	/// </summary>
	void SetShader(Shader* shader);

	/// <summary>
	/// Sets the sprite's texture to the given texture
	/// </summary>
	void SetTexture(Texture2D* tex);

	/// <summary>
	/// Sets the sprite's position to new position
	/// </summary>
	template<typename T>
	void SetPosition(T x, T y);

	/// <summary>
	/// Sets the sprite's position to new position
	/// </summary>
	void SetPosition(Vector2 newPosition);

	/// <summary>
	/// Sets the sprite's size to new size
	/// </summary>
	template<typename T>
	void SetSize(T x, T y);

	/// <summary>
	/// Sets the sprite's size to new size
	/// </summary>
	void SetSize(Vector2 newSize);

	Rectangle GetLocation()const;
	Vector2 GetPosition()const;
	Vector2 GetSize()const;
protected:
	uint buffer;
	uint vArray;

	Rectangle location;
	Shader*    shader;
	Texture2D* texture;
};

NS_END

#endif