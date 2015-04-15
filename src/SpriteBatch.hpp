#ifndef SPRITEBATCH_HPP
#define SPRITEBATCH_HPP

#include "Config.hpp"
#include "Sprite.hpp"

NS_BEGIN

struct SpriteInfo
{
	Rectangle location;
	Texture2D texture;
};

class SpriteBatch
{
public:
	SpriteBatch();
	~SpriteBatch();

	void Begin();
	void End();
private:
	bool active;
	std::vector<SpriteInfo> spriteList;
};

NS_END

#endif