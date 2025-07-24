#pragma once

class IGameState
{
public:
	virtual void Initialize() = 0;
	virtual void Update(float dt) = 0;
	virtual void Exit() = 0;
};

