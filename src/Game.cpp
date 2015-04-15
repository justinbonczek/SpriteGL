#include "Game.hpp"

NS_BEGIN

Game Game::instance;

Game::Game()
{}

Game::~Game()
{}

Game* Game::GetInstance()
{
	return &instance;
}

int Game::Initialize()
{
	Timer::Initialize();
	FileSystem::Initialize();

	if (!glfwInit())
		return -1;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		return -1;

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	Shader::Initialize();

	return true;
}

int Game::Run()
{
	LoadAssets();

	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		Timer::StartFrame();
		float dt = Timer::GetFrameTime();

		Update(dt);
		Draw();

		Timer::StopFrame();
	}

	Shutdown();
	return true;
}

void Game::LoadAssets()
{
	Texture2D* playerTexture = new Texture2D();
	playerTexture->LoadTexture("Textures/pikachu.png");

	Shader* spriteShader = new Shader();
	*spriteShader = Shader::SpriteShader;

	Sprite* player = new Sprite();
	player->SetTexture(*playerTexture);
	player->SetShader(*spriteShader);
	player->SetPosition(100, 100);
	//player->SetSize(100, 100);

	objects.push_back(player);
}

void Game::Update(float dt)
{
	for (Sprite* p : objects)
	{
		// TODO: Update Sprites
	}
}

void Game::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (Sprite* p : objects)
	{
		p->Draw();
	}

	glfwSwapBuffers(window);
	glfwPollEvents();

	glFlush();
}

void Game::Shutdown()
{
	glfwDestroyWindow(window);
}

NS_END