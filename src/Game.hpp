#ifndef GAME_HPP
#define GAME_HPP

#include "Config.hpp"
#include "SpriteGL.hpp"

NS_BEGIN

class Game
{
public:
	~Game();
	static Game* GetInstance();
	
	// TODO: Document game class
	int Initialize();
	int Run();
private:
	Game();
	static Game instance;

	Texture2D* mtex;
	Shader* mshader;
	Sprite* msprite;

	void LoadAssets();
	void Update(float dt);
	void Draw();
	void Shutdown();
	
	GLFWwindow* window;
};

NS_END

#endif