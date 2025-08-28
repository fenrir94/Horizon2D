#pragma once
#include <vector>
#include "object.h"

class IGameState
{
public:
	~IGameState();

	virtual void Initialize() = 0;
	virtual void Update(float dt) = 0;
	virtual void Exit() = 0;

	void ContainObject(Object* object);

	std::vector<Object*>& GetObjects();

protected:
	std::vector<Object*> m_Objects;
};

