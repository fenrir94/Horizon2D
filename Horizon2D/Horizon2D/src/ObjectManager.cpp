#include "ObjectManager.h"

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::Initialize()
{
}

void ObjectManager::Update(std::vector<Object>& objs, float dt)
{
	for (auto obj : objs)
	{
		obj.Update(dt);
	}
}

void ObjectManager::Destroy()
{
}
