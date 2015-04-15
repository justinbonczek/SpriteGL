#include "Shader.hpp"

#include "FileSystem.hpp"

NS_BEGIN

Shader Shader::SpriteShader;

Shader::Shader():
program(0)
{}

Shader::~Shader()
{}

void Shader::Initialize()
{
	SpriteShader.CreateShader("Shaders/Vertex/sprite.vert", Vertex);
	SpriteShader.CreateShader("Shaders/Geometry/sprite.geom", Geometry);
	SpriteShader.CreateShader("Shaders/Fragment/sprite.frag", Fragment);
}

bool Shader::CreateShader(const char* filepath, ShaderType type)
{
	if (!program)
		program = glCreateProgram();

	const char* shaderCode = FileSystem::LoadTextFile(filepath);

	if (!shaderCode)
		return 0;

	uint* index = 0;
	GLenum t;
	switch (type)
	{
	case Vertex:
		index = &vertex;
		t = GL_VERTEX_SHADER;
		break;
	case TessControl:
		index = &tessControl;
		t = GL_TESS_CONTROL_SHADER;
		break;
	case TessEval:
		index = &tessEval;
		t = GL_TESS_EVALUATION_SHADER;
		break;
	case Geometry:
		index = &geometry;
		t = GL_GEOMETRY_SHADER;
		break;
	case Fragment:
		index = &fragment;
		t = GL_FRAGMENT_SHADER;
		break;
	case Compute:
		index = &compute;
		t = GL_COMPUTE_SHADER;
		break;
	default:
		return 0;
	}

	*index = glCreateShader(t);
	glShaderSource(*index, 1, &shaderCode, 0);
	glCompileShader(*index);

	GLint check;
	glGetShaderiv(*index, GL_COMPILE_STATUS, &check);

	if (!check)
	{
		char log[1000] = { 0 };
		int length;
		glGetShaderiv(*index, GL_INFO_LOG_LENGTH, &length);
		glGetShaderInfoLog(*index, length, 0, log);
		std::cout << log << std::endl;

		return 0;
	}

	glAttachShader(program, *index);

	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &check);
	if (!check)
	{
		char log[1000] = { 0 };
		int length;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
		glGetShaderInfoLog(program, length, 0, log);
		std::cout << log << std::endl;
		glDeleteProgram(program);

		return 0;
	}

	return true;
}

void Shader::BindShader()
{
	uint n = glGetUniformLocation(program, "resolution");
	glUniform2f(n, WINDOW_WIDTH, WINDOW_HEIGHT);
	glUseProgram(program);
}

uint Shader::GetProgram()const
{
	return program;
}

NS_END