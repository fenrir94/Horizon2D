#include "StageState.h"
#include <Horizon2D/Horizon2D.h>
#include <iostream>


StageState::StageState()
{

}

StageState::~StageState()
{
}

void StageState::Initialize()
{
}

void StageState::Update(float dt)
{
	if (Horizon2D::IsKeyTriggered(GLFW_KEY_SPACE))
	{
		std::cout << "Stage" << std::endl;
	}

	if (Horizon2D::IsKeyTriggered(GLFW_KEY_M))
	{
		//std::cout << "Change" << std::endl;
		Horizon2D::ChangeGameState("MainMenu");
	}
}

void StageState::Exit()
{
}
