#include <Object.h>

Object::Object()
{
	m_Position = {0.f,0.f};
	m_Size = { 100.f, 100.f };
}

Object::Object(float x, float y, float width, float height)
{
	m_Position = { x, y };
	m_Size = { width, height };
}

Object::~Object()
{
}

void Object::Initialize()
{
}

void Object::Update(float dt)
{
}

void Object::Destroy()
{
}

glm::vec2 Object::GetPosition()
{
	return m_Position;
}

glm::vec2 Object::GetSize()
{
	return m_Size;
}
