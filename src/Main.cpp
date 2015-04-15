#include "SpriteGL.hpp"
#include "Timer.hpp"

using namespace sgl;

int main(int argc, char** argv)
{
	Timer::Initialize();

	// Initialize GLFW
	GLFWwindow* window;
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

	Texture2D t;
	t.LoadTexture("Textures/pikachu.png");

	Shader s;
	s.CreateShader("Shaders/Vertex/sprite.vert", Vertex);
	s.CreateShader("Shaders/Geometry/sprite.geom", Geometry);
	s.CreateShader("Shaders/Fragment/sprite.frag", Fragment);

	Sprite testSprite;
	testSprite.SetTexture(t);
	testSprite.SetShader(s);
	testSprite.SetSize(100, 100);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		Timer::StartFrame();
		float dt = Timer::GetFrameTime();

		glClear(GL_COLOR_BUFFER_BIT);

		testSprite.Translate(500 * dt, 500 * dt);
		testSprite.Draw();	

		glfwSwapBuffers(window);
		glfwPollEvents();

		glFlush();

		Timer::StopFrame();
	}

	glfwDestroyWindow(window);
	return 0;
}
