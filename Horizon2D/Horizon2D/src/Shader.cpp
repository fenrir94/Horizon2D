#include <glad/gl.h>
#include "Shader.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iostream>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
	std::string filePath = "C:/Users/BCA-PC5/Documents/Horizon2D/Horizon2D/Horizon2D/src/";
	std::string vertexDir = filePath + vertexPath;
	std::string fragDir = filePath + fragmentPath;

	std::cout << vertexDir << std::endl;
	std::cout << fragDir << std::endl;

	std::string vertSource = LoadShader(vertexDir);
	std::string fragSource = LoadShader(fragDir);
	
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

void Shader::SetUniform(const std::string& name, int value) const
{
	GLint location = glGetUniformLocation(m_programID, name.c_str());
	glUniform1i(location, value);
}

void Shader::SetUniform(const std::string& name, float value) const
{
	GLint location = glGetUniformLocation(m_programID, name.c_str());
	glUniform1f(location, value);
}

void Shader::SetUniform(const std::string& name, const glm::vec2& value) const
{
	GLint location = glGetUniformLocation(m_programID, name.c_str());
	if (location >= 0)
	{
		glUniform2f(location, value.x, value.y);
	}
}

void Shader::SetUniform(const std::string& name, const glm::vec3& value) const
{
	GLint location = glGetUniformLocation(m_programID, name.c_str());
	if (location >= 0)
	{
		glUniform3f(location, value.x, value.y, value.z);
	}
}

void Shader::SetUniform(const std::string& name, const glm::vec4& value) const
{
	GLint location = glGetUniformLocation(m_programID, name.c_str());
	if (location >= 0)
	{
		glUniform4f(location, value.x, value.y, value.z, value.w);
	}
}

void Shader::SetUniform(const std::string& name, const glm::mat4& value) const
{
	GLint loc = glGetUniformLocation(m_programID, name.c_str());
	if (loc >= 0) {
		glUniformMatrix4fv(loc, 1, GL_FALSE, &value[0][0]);
	}
}

std::string Shader::LoadShader(const std::string& path)
{
	std::ifstream file(path);
	if (!file.is_open()) throw std::runtime_error("Shader File Error");

	std::stringstream ss;
	ss << file.rdbuf();
	return ss.str();
}

GLuint Shader::CompileShader(GLenum type, const std::string& source)
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
		std::cerr << "Shader Compile Error:\n" << info << std::endl;
		//throw std::runtime_error("Shader compilation failed.");
	}

	return shader;
}
