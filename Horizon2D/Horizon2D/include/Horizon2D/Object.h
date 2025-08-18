#pragma once

#include "glm/glm.hpp"

class Object {
public:
	Object();
	Object(float x, float y, float width, float height);
	virtual ~Object();

	void Initialize();
	virtual void Update(float dt);
	void Destroy();

	glm::vec2 GetPosition();
	glm::vec2 GetSize();

protected:
	glm::vec2 m_Position;
	glm::vec2 m_Size;
};