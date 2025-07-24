#pragma once

class IGameState
{
public:
	void Initialize();
	void Update(float dt);
	void Exit();
};

