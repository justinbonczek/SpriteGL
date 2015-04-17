#include "Sprite.hpp"

NS_BEGIN

Sprite::Sprite()
{
	glGenVertexArrays(1, &vArray);
	glBindVertexArray(vArray);
	
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	// Position & Size
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)(sizeof(float) * 2));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}

Sprite::~Sprite()
{

}

void Sprite::Update(float dt)
{

}

void Sprite::Draw()
{
	glBindVertexArray(vArray);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	// TODO: Move width/height math to CPU
	float data[4] = { ScreenToWorld(location.Position()).x, ScreenToWorld(location.Position()).y,
		ScreenToWorld(location.Size()).x, ScreenToWorld(location.Size()).y };
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 4, data, GL_STATIC_DRAW);

	shader->BindShader();
	texture->BindTexture(shader->GetProgram());

	glDrawArrays(GL_POINTS, 0, 1);
}

template<typename T>
void Sprite::Translate(T x, T y)
{
	location.x += x;
	location.y += y;
}

template void Sprite::Translate<int>(int, int);
template void Sprite::Translate<uint>(uint, uint);
template void Sprite::Translate<float>(float, float);
template void Sprite::Translate<double>(double, double);

void Sprite::Translate(Vector2 translation)
{
	location.x += (int)translation.x;
	location.y += (int)translation.y;
}

template<typename T>
void Sprite::Scale(T x, T y)
{
	location.width *= (uint)x;
	location.height *= (uint)y;
}

template void Sprite::Scale<int>(int, int);
template void Sprite::Scale<uint>(uint, uint);
template void Sprite::Scale<float>(float, float);
template void Sprite::Scale<double>(double, double);

void Sprite::Scale(Vector2 scale)
{
	location.width = (int)((float)location.width * scale.x);
	location.height = (int)((float)location.height * scale.y);
}

void Sprite::Rotate(float angle)
{
	// TODO: Implement sprite rotation
}

void Sprite::SetShader(Shader* _shader)
{
	shader = _shader;
}

void Sprite::SetTexture(Texture2D* tex)
{
	texture = tex;
	if (!(location.width) && !(location.height))
	{
		location.width = tex->GetWidth();
		location.height = tex->GetHeight();
	}
}

template<typename T>
void Sprite::SetPosition(T x, T y)
{
	location.x = (int)x;
	location.y = (int)y;
}

template void Sprite::SetPosition<int>(int, int);
template void Sprite::SetPosition<uint>(uint, uint);
template void Sprite::SetPosition<float>(float, float);
template void Sprite::SetPosition<double>(double, double);

void Sprite::SetPosition(Vector2 newPosition)
{
	location.x = (int)newPosition.x;
	location.y = (int)newPosition.y;
}

template<typename T>
void Sprite::SetSize(T x, T y)
{
	location.width = (uint)x;
	location.height = (uint)y;
}

template void Sprite::SetSize<int>(int, int);
template void Sprite::SetSize<uint>(uint, uint);
template void Sprite::SetSize<float>(float, float);
template void Sprite::SetSize<double>(double, double);

void Sprite::SetSize(Vector2 newSize)
{
	location.width = (int)newSize.x;
	location.height = (int)newSize.y;
}

Rectangle Sprite::GetLocation()const
{
	return location;
}

Vector2 Sprite::GetPosition()const
{
	return location.Position();
}

Vector2 Sprite::GetSize()const
{
	return location.Size();
}

NS_END