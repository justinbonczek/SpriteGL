#include "SpriteBatch.hpp"

NS_BEGIN

SpriteBatch::SpriteBatch()
{}

SpriteBatch::~SpriteBatch()
{}

void SpriteBatch::Begin()
{
	if (active)
		throw "SpriteBatch Begin() called on an already active SpriteBatch.";
	active = true;
}

void SpriteBatch::End()
{
	active = false;
}

NS_END