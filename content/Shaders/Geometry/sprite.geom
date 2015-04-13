#version 430

layout(points) in;
layout(triangle_strip) out;
layout(max_vertices = 4) out;

in vec2 spritePosition[];
in vec2 spriteSize[];

out vec2 uv;

void main()
{
	gl_Position = vec4(spritePosition[0], 0.0, 1.0);
	uv = vec2(0.0, 0.0);
	EmitVertex();

	gl_Position = vec4(spritePosition[0].x - (-1.0 - spriteSize[0].x), 
		spritePosition[0].y, 0.0, 1.0);
		uv = vec2(1.0, 0.0);
	EmitVertex();

	gl_Position = vec4(spritePosition[0].x, spritePosition[0].y - (1.0 - spriteSize[0].y), 0.0, 1.0);
	uv = vec2(0.0, 1.0);
	EmitVertex();

	gl_Position = vec4(spritePosition[0].x - (-1.0 - spriteSize[0].x), 
		spritePosition[0].y - (1.0 - spriteSize[0].y), 0.0, 1.0);
	uv = vec2(1.0, 1.0);
	EmitVertex();

	EndPrimitive();
}