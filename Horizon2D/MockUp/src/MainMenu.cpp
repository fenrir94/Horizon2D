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

	Horizon2D::DrawRectangle(0, 0, 100, 100, 1, 0, 0, 1);
}

void MainMenu::Exit()
{
}
