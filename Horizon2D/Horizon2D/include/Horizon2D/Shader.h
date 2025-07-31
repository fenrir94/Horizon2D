#pragma once
#include <glm/glm.hpp>
#include <string>
using GLuint = unsigned int;
using GLenum = unsigned int;
class Shader
{
public:	
	

	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	void Use() const;

	void SetUniform(const std::string& name, int value) const;
	void SetUniform(const std::string& name, float value) const;
	void SetUniform(const std::string& name, const glm::vec2& value) const;
	void SetUniform(const std::string& name, const glm::vec3& value) const;
	void SetUniform(const std::string& name, const glm::vec4& value) const;
	void SetUniform(const std::string& name, const glm::mat4& value) const;


	std::string LoadShader(const std::string& path);

	GLuint CompileShader(GLenum type, const std::string& source);

private:
	GLuint m_programID;
};

