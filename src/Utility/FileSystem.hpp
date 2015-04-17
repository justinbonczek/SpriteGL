#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include "..\Config.hpp"
#include <fstream>

struct Image;

NS_BEGIN

struct Image;

class FileSystem
{
public:
	~FileSystem();
	static FileSystem* GetInstance();

	/// <summary>
	/// Initializes FileSystem
	/// </summary>
	static bool Initialize();

	/// <summary>
	/// 
	/// </summary>
	static char* LoadTextFile(const char* filepath);

	/// <summary>
	/// Internal function to handle PNG loading
	/// </summary>
	static Image LoadPNGFromFile(const char* filepath);
private:
	FileSystem();
	static FileSystem instance;
};

NS_END

#endif