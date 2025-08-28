#pragma once
#include "Object.h"
#include <vector>

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Initialize();
	void Update(std::vector<Object*>& objs, float dt);
	void Destroy();

private:
};

