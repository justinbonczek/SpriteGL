#ifndef TEXTRENDERER_HPP
#define TEXTRENDERER_HPP

#include "../Config.hpp"
#include <ft2build.h>
#include <freetype.h>

#include "Texture.hpp"
#include "Shader.hpp"

NS_BEGIN

class TextRenderer
{
public:
	~TextRenderer();
	static TextRenderer* GetInstance();

	static int Initialize();

	/// <summary>
	/// 
	/// </summary>
	static void RenderText(const char* text, Vector2 position);
	/// <summary>
	/// 
	/// </summary>
	template<typename T>
	static void RenderText(const char*, T, T);

	/// <summary>
	/// 
	/// </summary>
	static void SetFont(const char* fontfilepath);

	/// <summary>
	/// 
	/// </summary>
	static void SetFontSize(int size);

	/// <summary>
	/// 
	/// </summary>
	static void SetFontColor(Vector4 color);
	
	/// <summary>
	/// 
	/// </summary>
	template<typename T>
	static void SetFontColor(T r, T g, T b, T a);
private:
	TextRenderer();
	static TextRenderer instance;
	static uint fontsize;

	static FT_Library ft;
	static FT_Face face;
	static uint atlasWidth;

	static Texture2D texture;
	static Shader textShader;
	static Vector4 fontColor;
};

NS_END

#endif