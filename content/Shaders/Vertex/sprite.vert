#version 430

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 size;

out vec2 spritePosition;
out vec2 spriteSize;

void main()
{
	spritePosition = position;
	spriteSize = size;
}