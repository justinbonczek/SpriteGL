#include "Texture.hpp"
#include "FileSystem.hpp"

NS_BEGIN

Texture2D::Texture2D()
{}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &texture);
}

bool Texture2D::LoadTexture(const char* filepath)
{
	// TODO: ERROR CHECKING

	image = FileSystem::LoadPNGFromFile(filepath);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexImage2D(GL_TEXTURE_2D, NULL, GL_RGBA, image.width, image.height, NULL, GL_RGBA, GL_UNSIGNED_BYTE, &image.data[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0);

	return true;
}

void Texture2D::BindTexture(uint const program)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1f(glGetUniformLocation(program, "tex"), 0);
}

uint Texture2D::GetTexture()const
{
	return texture;
}

uint Texture2D::GetWidth()const
{
	return image.width;
}

uint Texture2D::GetHeight()const
{
	return image.height;
}

Vector2 Texture2D::GetSize()const
{
	return Vector2(image.width, image.height);
}
NS_END