#include <Horizon2D/Horizon2D.h>
#include "MainMenu.h"
#include "StageState.h"


int main()
{
	GameManager& GameManager = GameManager::GetInstance();
	GameManager.Initialize(800, 600, "MockUp");
	Horizon2D::RegisterState("MainMenu", []() {
		return std::make_unique<MainMenu>();
	});
	Horizon2D::RegisterState("StageState", []() {
		return std::make_unique<StageState>();
	});

	Horizon2D::ChangeGameState("MainMenu");

	GameManager.Run();
	GameManager.Destroy();

	

	return 0;
}