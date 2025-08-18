#include "Character.h"
#include <iostream>

Character::Character()
	:Object()
{
	m_lifePoint = 0;
}

Character::Character(float x, float y, float width, float height, int lifePoint)
	: Object(x, y, width, height)
{
	m_lifePoint = lifePoint;
}

Character::~Character()
{

}

void Character::Update(float dt)
{
	Object::Update(dt);
	std::cout << "Update" << std::endl;
}
