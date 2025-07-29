#pragma once
#include <Horizon2D/IGameState.h>

class StageState : public IGameState
{
public:
	StageState();
	~StageState();

	void Initialize() override;
	void Update(float dt) override;
	void Exit() override;

private:
};