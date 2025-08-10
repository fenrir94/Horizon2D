#pragma once

#include "glm/glm.hpp"

class Object {
public:
	Object();
	Object(float x, float y, float width, float height);
	virtual ~Object();

	void Initialize();
	void Update(float dt);
	void Destroy();


private:
	glm::vec2 m_Position;
	glm::vec2 m_Size;
};