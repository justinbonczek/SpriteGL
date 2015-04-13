#version 430

uniform sampler2D tex;

in vec2 uv;

out vec4 finalColor;

void main()
{
	finalColor = texture(tex, uv);
}