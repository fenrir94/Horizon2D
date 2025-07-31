#pragma once
#include <Horizon2D/GameManager.h> 
#include <Horizon2D/InputManager.h>
#include <Horizon2D/Statemanager.h>
#include <Horizon2D/RenderManager.h>

// Facade 
namespace Horizon2D
{

	void RegisterState(const std::string& name, StateManager::StateFactory factory);

	void ChangeGameState(const std::string& name);

	bool IsKeyPressed(int key);
	bool IsKeyTriggered(int key);

	void DrawRectangle(float x, float y, float width, float height, float r, float g, float b, float alpha);
}

