#version 430

layout(location = 0) in vec4 coord;

void main(void)
{
	gl_Position = vec4(coord.xy, 0, 1);
}