#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "..\Config.hpp"

NS_BEGIN

struct Image
{
	std::vector<unsigned char> data;
	uint width, height;
};

class Texture2D
{
public:
	Texture2D();
	~Texture2D();

	void Generate(GLint filter, GLint address);

	/// <summary>
	/// Loads texture data from image at filepath
	/// </summary>
	bool LoadTexture(const char* filepath);

	/// <summary>
	/// Binds the texture to the pipeline for use
	/// </summary>
	void BindTexture();

	/// <summary>
	/// Binds the texture to the pipeline for use
	/// </summary>
	void BindTexture(uint const program);

	/// <summary>
	/// 
	/// </summary>
	void RenderToTexture(GLenum format, GLint type, uint width, uint height, const GLvoid* data);

	/// <summary>
	/// Returns the texture address
	/// </summary>
	uint GetTexture()const;

	/// <summary>
	/// Returns the texture's width in pixels
	/// </summary>
	uint GetWidth()const;

	/// <summary>
	/// Returns the texture's height in pixels
	/// </summary>
	uint GetHeight()const;

	/// <summary>
	/// Returns the texture's width and height in pixels
	/// </summary>
	Vector2 GetSize()const;
private:
	Image image;
	uint texture;
};

NS_END

#endif