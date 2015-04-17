#include "Game.hpp"
NS_BEGIN

Game Game::instance;

Game::Game()
{}

Game::~Game()
{
	delete mtex;
	delete mshader;
	delete msprite;
}

Game* Game::GetInstance()
{
	return &instance;
}

int Game::Initialize()
{
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

	// Subsystem initializaion
	Timer::Initialize();
	FileSystem::Initialize();
	Shader::Initialize();
	TextRenderer::Initialize();

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
	mtex = new Texture2D();
	mshader = new Shader();
	msprite = new Sprite();
	mtex->LoadTexture("Textures/pikachu.png");
	*mshader = Shader::SpriteShader;

	msprite->SetTexture(mtex);
	msprite->SetShader(mshader);
	msprite->SetPosition(250, 50);
	msprite->SetSize(250, 250);

	TextRenderer::SetFontColor(0.8, 0.4, 0.6, 1.0);
	TextRenderer::SetFont("Fonts/impact.ttf");
	TextRenderer::SetFontSize(36);
}

void Game::Update(float dt)
{

}

void Game::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	msprite->Draw();

	TextRenderer::RenderText("Example Text.", 100, 100);

	glfwSwapBuffers(window);
	glfwPollEvents();

	glFlush();
}

void Game::Shutdown()
{
	glfwDestroyWindow(window);
}
NS_END