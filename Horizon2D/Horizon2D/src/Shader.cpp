#include "Shader.h"
#include <fstream>
#include <sstream>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
	std::string vertSource = LoadShader(vertexPath);
	std::string fragSource = LoadShader(fragmentPath);
	
	GLuint vertShader = CompileShader(GL_VERTEX_SHADER, vertSource);
	GLuint fragShader = CompileShader(GL_FRAGMENT_SHADER, fragSource);
	
	m_programID = glCreateProgram();
	glAttachShader(m_programID, vertShader);
	glAttachShader(m_programID, fragShader);
	glLinkProgram(m_programID);

	GLint success;
	glGetProgramiv(m_programID, GL_LINK_STATUS, &success);
	if (!success)
	{
		char info[512];
		glGetShaderInfoLog(m_programID, 512, nullptr, info);
	}

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
}

void Shader::Use() const
{
	glUseProgram(m_programID);
}

std::string LoadShader(const std::string& path)
{
	std::ifstream file(path);
	if (!file.is_open()) throw std::runtime_error("Shader File Error");

	std::stringstream ss;
	ss << file.rdbuf();
	return ss.str();
}

GLuint CompileShader(GLenum type, const std::string& source)
{
	GLuint shader = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(shader, 1, &src, nullptr);
	glCompileShader(shader);

	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char info[512];
		glGetShaderInfoLog(shader, 512, nullptr, info);
		//std::cerr << "Shader Compile Error:\n" << info << std::endl;
		//throw std::runtime_error("Shader compilation failed.");
	}

	return shader;
}
