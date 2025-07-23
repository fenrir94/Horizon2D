#include "Horizon2D/GameManager.h"


int main()
{
	GameManager& GameManager = GameManager::getInstance();
	GameManager.Initialize(1000, 800, "MockUp");
	GameManager.Run();
	GameManager.Destroy();

	return 0;
}