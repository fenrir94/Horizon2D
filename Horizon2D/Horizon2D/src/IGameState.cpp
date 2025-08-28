#include "IGameState.h"

IGameState::~IGameState()
{
	for (auto obj: m_Objects)
	{
		delete obj;
	}
	m_Objects.clear();
}

void IGameState::ContainObject(Object* object)
{
	m_Objects.emplace_back(object);
}

std::vector<Object*>& IGameState::GetObjects()
{
	return m_Objects;
}
