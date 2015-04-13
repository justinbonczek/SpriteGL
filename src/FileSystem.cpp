#include "FileSystem.hpp"

#include "Texture.hpp"

NS_BEGIN

FileSystem FileSystem::instance;

FileSystem::FileSystem()
{}

FileSystem::~FileSystem()
{}

FileSystem* FileSystem::GetInstance()
{
	return &instance;
}

bool FileSystem::Initialize()
{
	return true;
}

char* FileSystem::LoadTextFile(const char* filepath)
{
	char* output = 0;

	std::ifstream in(filepath, std::ios_base::binary);
	if (in.is_open())
	{
		in.seekg(0, std::ios::end);
		size_t length = (size_t)in.tellg();
		output = new char[length + 1];
		in.seekg(0, std::ios::beg);

		in.read(output, length);
		output[length] = '\0';
		in.close();
	}

	return output;
}

/// <summary>
/// Internal function to handle PNG loading
/// </summary>
Image FileSystem::LoadPNGFromFile(const char* filepath)
{
	Image image;
	unsigned error = lodepng::decode(image.data, image.width, image.height, filepath);

	if (error != 0)
		std::cout << "ERROR! Could not load png." << std::endl;

	return image;
}

NS_END