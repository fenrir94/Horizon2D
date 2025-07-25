#pragma once
#include <Horizon2D/GameManager.h> 
#include <Horizon2D/InputManager.h>
#include <Horizon2D/Statemanager.h>

// Facade 
namespace Horizon2D
{

	void RegisterState(const std::string& name, StateManager::StateFactory factory);

	void ChangeGameState(const std::string& name);

	bool IsKeyPressed(int key);
}

