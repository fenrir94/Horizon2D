#pragma once
#include <vector>
#include "StateManager.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Initialize();
	void Update( float dt);
	void Destroy();

private:
	StateManager& stateManager;
};

