#include "Game.hpp"

using namespace sgl;

int main(int argc, char** argv)
{
	Game* game = Game::GetInstance();
	if (!game->Initialize())
		return 0;
	return game->Run();
}