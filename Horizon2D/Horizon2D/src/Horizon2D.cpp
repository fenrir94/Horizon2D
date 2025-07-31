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

void Horizon2D::DrawRectangle(float x, float y, float width, float height, float r, float g, float b, float alpha)
{
	GameManager::GetInstance().GetRenderManager()->DrawRectangle(x, y, width, height, r, g, b, alpha);
}
