#ifndef TEXTRENDERER_HPP
#define TEXTRENDERER_HPP

#include "Config.hpp"
#include <ft2build.h>
#include <freetype.h>
NS_BEGIN

class TextRenderer
{
public:
	~TextRenderer();
	static TextRenderer* GetInstance();

	int Initialize();
private:
	TextRenderer();
	static TextRenderer instance;
};

NS_END

#endif