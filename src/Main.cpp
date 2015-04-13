#include "SpriteGL.hpp"

using namespace sgl;

int main(int argc, char** argv)
{
	// Initialize GLFW
	GLFWwindow* window;
	if (!glfwInit())
		return -1;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
	glfwMakeContextCurrent(window);
	
	glewExperimental = GL_TRUE;
	// Initialize GLEW
	if (glewInit() != GLEW_OK)
		return -1;

	glEnable(GL_TEXTURE_2D);

	Texture2D t;
	t.LoadTexture("Textures/pikachu.png");

	Shader s;
	s.CreateShader("Shaders/Vertex/sprite.vert", Vertex);
	s.CreateShader("Shaders/Geometry/sprite.geom", Geometry);
	s.CreateShader("Shaders/Fragment/sprite.frag", Fragment);

	Sprite testSprite;
	testSprite.SetTexture(t);
	testSprite.SetShader(s);

	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		testSprite.Draw();	

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	return 0;
}
