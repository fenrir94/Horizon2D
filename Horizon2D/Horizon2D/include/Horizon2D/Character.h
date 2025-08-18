#pragma once
#include "Object.h"

class Character: public Object
{
public:
	Character();
	Character(float x, float y, float width, float height, int lifePoint);
	virtual ~Character();

	void Update(float dt) override;

protected:
	int m_lifePoint;
};

