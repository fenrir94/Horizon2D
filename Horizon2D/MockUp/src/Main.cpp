#include "Horizon2D/GameManager.h"
#include "Horizon2D/InputManager.h"
#include <Horizon2D/Horizon2D.h>
#include "MainMenu.h"

int main()
{
	GameManager& GameManager = GameManager::GetInstance();
	GameManager.Initialize(1000, 800, "MockUp");
	Horizon2D::RegisterState("MainMenu", []() {
		return std::make_unique<MainMenu>();
	});
	Horizon2D::ChangeGameState("MainMenu");

	GameManager.Run();
	GameManager.Destroy();

	return 0;
}