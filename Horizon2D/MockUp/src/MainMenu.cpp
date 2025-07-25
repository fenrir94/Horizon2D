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
	if (Horizon2D::IsKeyPressed(GLFW_KEY_SPACE))
	{
		std::cout << "Main" << std::endl;
	}
}

void MainMenu::Exit()
{
}
