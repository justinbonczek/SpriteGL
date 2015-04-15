#ifndef SHADER_HPP
#define SHADER_HPP

#include "Config.hpp"

NS_BEGIN

enum ShaderType
{
	Vertex,
	TessControl,
	TessEval,
	Geometry,
	Fragment,
	Compute
};

class Shader
{
public:
	Shader();
	~Shader();

	static Shader SpriteShader;

	/// <summary>
	/// Creates a shader of given type from file at given path
	/// </summary>
	bool CreateShader(const char* filepath, ShaderType type);

	/// <summary>
	/// Binds the shader to the pipeline for use
	/// </summary>
	void BindShader();

	/// <summary>
	/// Returns the shader program index
	/// </summary>
	uint GetProgram()const;
private:
	uint vertex, tessControl, tessEval, geometry, fragment, compute;
	uint program;
	uint resolution;
};

NS_END

#endif