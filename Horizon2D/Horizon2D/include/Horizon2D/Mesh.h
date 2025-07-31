#pragma once
#include <vector>
using GLuint = unsigned int;
class Mesh
{
public:
	Mesh(const std::vector<float>& vertices);
	void Draw() const;

private:
	GLuint m_vao;
	GLuint m_vbo;
};

