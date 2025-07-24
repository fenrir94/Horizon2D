#include "Horizon2D/GameManager.h"
#include "Horizon2D/InputManager.h"

int main()
{
	GameManager& GameManager = GameManager::GetInstance();
	GameManager.Initialize(1000, 800, "MockUp");
	GameManager.Run();
	GameManager.Destroy();
	


	return 0;
}