#include "TextRenderer.hpp"

#include <cmath>

NS_BEGIN

TextRenderer TextRenderer::instance;
FT_Library TextRenderer::ft;
FT_Face TextRenderer::face;
uint TextRenderer::atlasWidth;
uint TextRenderer::fontsize;

Texture2D TextRenderer::texture;
Shader TextRenderer::textShader;
Vector4 TextRenderer::fontColor;

TextRenderer::TextRenderer()
{}

TextRenderer::~TextRenderer()
{}

int TextRenderer::Initialize()
{
	textShader = Shader::TextShader;
	texture.Generate(GL_LINEAR, GL_CLAMP_TO_EDGE);
	fontsize = 16;

	if (FT_Init_FreeType(&ft))
	{
		std::cout << "Failed to initialize FreeType." << std::endl;
		return -1;
	}
	return 0;
}

void TextRenderer::RenderText(const char* text, Vector2 position)
{
	FT_Set_Pixel_Sizes(face, 0, fontsize);
	// TODO: Optimize
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 4, 0);
	glEnableVertexAttribArray(0);

	textShader.BindShader();

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	
	// Text render loop
	for (const char* t = text; *t; t++)
	{
		FT_GlyphSlot g;
		if (FT_Load_Char(face, *t, FT_LOAD_RENDER))
			continue;
		g = face->glyph;

		texture.RenderToTexture(GL_RED, GL_UNSIGNED_BYTE, g->bitmap.width, g->bitmap.rows, g->bitmap.buffer);

		position = ScreenToWorld(Vector2(position.x + g->bitmap_left, position.y - g->bitmap_top));
		Vector2 wh = ScreenToWorld(Vector2(g->bitmap.width, g->bitmap.rows));

		float x2 = position.x;
		float y2 = position.y;
		float w = wh.x;
		float h = wh.y;

		GLfloat box[4][4] = {
				{ x2			 , y2			 , 0.0f, 0.0f },
				{ x2 - (-1.0 - w), y2			 , 1.0f, 0.0f },
				{ x2			 , y2 - (1.0 - h), 0.0f, 1.0f },
				{ x2 - (-1.0 - w), y2 - (1.0 - h), 1.0f, 1.0f },
		};

		GLfloat color[4] = { fontColor.x, fontColor.y, fontColor.z, fontColor.w };
		glUniform4fv(glGetUniformLocation(textShader.GetProgram(), "color"), 1, color);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 16, box, GL_DYNAMIC_DRAW);

		texture.BindTexture(textShader.GetProgram());
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		position.x += (g->advance.x >> 6);
		position.y += (g->advance.y >> 6);
	}

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
}

template<typename T>
void TextRenderer::RenderText(const char* text, T x, T y)
{
	FT_Set_Pixel_Sizes(face, 0, fontsize);
	// TODO: Optimize
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 4, 0);
	glEnableVertexAttribArray(0);

	textShader.BindShader();

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// Text render loop
	for (const char* t = text; *t; t++)
	{
		FT_GlyphSlot g;
		if (FT_Load_Char(face, *t, FT_LOAD_RENDER))
			continue;
		g = face->glyph; 

		texture.RenderToTexture(GL_RED, GL_UNSIGNED_BYTE, g->bitmap.width, g->bitmap.rows, g->bitmap.buffer);
		
		Vector2 position = ScreenToWorld(Vector2(x + g->bitmap_left, y - g->bitmap_top));
		Vector2 wh = ScreenToWorld(Vector2(g->bitmap.width, g->bitmap.rows));

		float x2 = position.x;
		float y2 = position.y;
		float w = wh.x;
		float h = wh.y;

		GLfloat box[4][4] = {
				{ x2			 , y2			  , 0.0f, 0.0f },
				{ x2 - (-1.0 - w), y2			  , 1.0f, 0.0f },
				{ x2			 , y2 - (1.0 - h) , 0.0f, 1.0f },
				{ x2 - (-1.0 - w), y2 - (1.0 - h) , 1.0f, 1.0f },
		};

		GLfloat color[4] = { fontColor.x, fontColor.y, fontColor.z, fontColor.w };
		glUniform4fv(glGetUniformLocation(textShader.GetProgram(), "color"), 1, color);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 16, box, GL_DYNAMIC_DRAW);

		texture.BindTexture(textShader.GetProgram());
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		
		x += (g->advance.x >> 6);
		y += (g->advance.y >> 6);
	}

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
}

template void TextRenderer::RenderText<int>(const char*, int, int);
template void TextRenderer::RenderText<float>(const char*, float, float);
template void TextRenderer::RenderText<double>(const char*, double, double);

void TextRenderer::SetFont(const char* fontfilepath)
{
	if (FT_New_Face(ft, fontfilepath, 0, &face))
		std::cout << "Failed to load font." << std::endl;

	// TODO: Texture Atlasing
	//FT_GlyphSlot g = face->glyph;
	//uint w = 0;
	//uint h = 0;
	//
	//texture.BindTexture(textShader.GetProgram());
	//// Create Texture Atlas
	//for (int i = 32; i < 128; i++)
	//{
	//	if (FT_Load_Char(face, i, FT_LOAD_RENDER))
	//		continue;
	//	w += g->bitmap.width;
	//	h = std::max(h, g->bitmap.rows);
	//
	//	atlasWidth = w;
	//}
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, w, h, 0, GL_ALPHA, GL_UNSIGNED_BYTE, 0);
	//uint x = 0;
	//for (int i = 32; i < 128; i++)
	//{
	//	if (FT_Load_Char(face, i, FT_LOAD_RENDER))
	//		continue;
	//
	//	glTexSubImage2D(GL_TEXTURE_2D, 0, x, 0, g->bitmap.width, g->bitmap.rows, GL_ALPHA, GL_UNSIGNED_BYTE, g->bitmap.buffer);
	//	x += g->bitmap.width;
	//}
}
void TextRenderer::SetFontSize(int size)
{
	fontsize = size;
}

void TextRenderer::SetFontColor(Vector4 color)
{
	fontColor.x = color.x;
	fontColor.y = color.y;
	fontColor.z = color.z;
	fontColor.w = color.w;
}

template<typename T>
void TextRenderer::SetFontColor(T r, T g, T b, T a)
{
	fontColor.x = r;
	fontColor.y = g;
	fontColor.z = b;
	fontColor.w = a;
}

template void TextRenderer::SetFontColor<float>(float, float, float, float);
template void TextRenderer::SetFontColor<double>(double, double, double, double);

NS_END