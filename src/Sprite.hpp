#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Config.hpp"
#include "Texture.hpp"
#include "Shader.hpp"
#include "Transform.hpp"

NS_BEGIN

class Sprite
{
public:
	Sprite();
	~Sprite();

	/// <summary>
	/// Sets the sprite's shader to the given shader
	/// </summary>
	void SetShader(Shader& shader);

	/// <summary>
	/// Sets the sprite's texture to the given texture
	/// </summary>
	void SetTexture(Texture2D& tex);

	/// <summary>
	/// Sets the sprite's location to the given rectangle
	/// </summary>
	void SetLocation(Rectangle rect);

	/// <summary>
	/// Renders the sprite to the screen
	/// </summary>
	void Draw();
private:
	uint buffer;
	uint vArray;

	Rectangle location;

	Shader    shader;
	Texture2D texture;
};

NS_END

#endif