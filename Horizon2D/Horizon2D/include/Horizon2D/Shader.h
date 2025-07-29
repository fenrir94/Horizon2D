#pragma once
#include <glad/gl.h>
#include <string>


std::string LoadShader(const std::string& path);

GLuint CompileShader(GLenum type, const std::string& source);

class Shader
{
public:	
	GLuint m_programID;

	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	void Use() const;

private:

};

