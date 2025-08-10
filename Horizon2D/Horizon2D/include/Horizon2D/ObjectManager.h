#pragma once
#include <vector>
#include "Object.h"

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

