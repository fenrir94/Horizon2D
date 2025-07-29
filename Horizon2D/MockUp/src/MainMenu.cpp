#include "MainMenu.h"
#include <Horizon2D/Horizon2D.h>
#include <iostream>

MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{

}

void MainMenu::Initialize()
{
}

void MainMenu::Update(float dt)
{
	if (Horizon2D::IsKeyTriggered(GLFW_KEY_SPACE))
	{
		std::cout << "Main" << std::endl;
	}


	if (Horizon2D::IsKeyTriggered(GLFW_KEY_M))
	{
		//std::cout << "Change" << std::endl;
		Horizon2D::ChangeGameState("StageState");
	}
}

void MainMenu::Exit()
{
}
