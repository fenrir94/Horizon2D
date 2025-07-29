#include "Horizon2D.h"

void Horizon2D::RegisterState(const std::string& name, StateManager::StateFactory factory)
{
	GameManager::GetInstance().GetStateManager()->RegisterState(name, factory);
}

void Horizon2D::ChangeGameState(const std::string& name)
{
	GameManager::GetInstance().GetStateManager()->ChangeGameState(name);
}

bool Horizon2D::IsKeyPressed(int key)
{
	return 	GameManager::GetInstance().GetInputManager()->IsKeyPressed(key);
}

bool Horizon2D::IsKeyTriggered(int key)
{
	return GameManager::GetInstance().GetInputManager()->IsKeyTriggered(key);
}
