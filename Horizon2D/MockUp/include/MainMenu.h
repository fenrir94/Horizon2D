#pragma once
#include <Horizon2D/IGameState.h>

class MainMenu : public IGameState
{
public:
	MainMenu();
	~MainMenu();

	void Initialize() override;
	void Update(float dt) override;
	void Exit() override;

private:
};