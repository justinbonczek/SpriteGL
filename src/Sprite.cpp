#include "Sprite.hpp"

NS_BEGIN

Sprite::Sprite()
{
	location.x = 100;
	location.y = 100;
	location.width = 500;
	location.height = 500;
	float data[4] = { ScreenToWorld(location.Position()).x, ScreenToWorld(location.Position()).y, 
		ScreenToWorld(location.Size()).x, ScreenToWorld(location.Size()).y };

	glGenVertexArrays(1, &vArray);
	glBindVertexArray(vArray);
	
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 4, data, GL_STATIC_DRAW);

	// Position & Size
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)(sizeof(float) * 2));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}

Sprite::~Sprite()
{}

void Sprite::SetShader(Shader& shader)
{
	this->shader = shader;
}

void Sprite::SetTexture(Texture2D& tex)
{
	texture = tex;
}

void Sprite::SetLocation(Rectangle rect)
{
	location = rect;
}

void Sprite::Draw()
{
	shader.BindShader();
	texture.BindTexture(shader.GetProgram());

	glBindVertexArray(vArray);
	glDrawArrays(GL_POINTS, 0, 1);
}

NS_END