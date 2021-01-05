#pragma once
#include <string>
class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	void use();
	void checkCompileErrors(unsigned int ID, std::string type);
	unsigned int ID; // Shader Program ID

private:
	std::string vertexString;
	std::string fragmentString;
	const char* vertexSource;
	const char* fragmentSource;
	

};

