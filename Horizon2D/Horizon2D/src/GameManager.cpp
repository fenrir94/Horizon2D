#include "GameManager.h"
#include <iostream>
#include <GLFW/glfw3.h>	

GameManager::GameManager()
{
	m_isRunning = true;
}

GameManager::~GameManager()
{
}

GameManager& GameManager::GetInstance()
{
	static GameManager instance;
	return instance;
}


void GameManager::Initialize(int width, int height, const char* title)
{
	m_WindowManager = &WindowManager::GetInstance();
	m_WindowManager->Initialize(width, height, title);
	m_WindowManager->CreateWindow();

	m_InputManager.Initialize();
}



void GameManager::Run()
{
	std::cout << "Horizon" << std::endl;

	while (m_isRunning && !glfwWindowShouldClose(m_WindowManager->m_Window))
	{
		m_WindowManager->ClearWindow();
		glfwPollEvents();
		

		m_InputManager.Update(m_WindowManager->m_Window);

		// StateManager
		
		if (m_InputManager.IsKeyPressed(GLFW_KEY_SPACE))
		{
			std::cout << "Space" << std::endl;
		}

		
		if (m_InputManager.IsKeyPressed(GLFW_KEY_ESCAPE))
		{
			glfwSetWindowShouldClose(m_WindowManager->m_Window, true);
		}

		m_WindowManager->SwapWindowBuffer();
	}
}

void GameManager::Destroy()
{
	m_WindowManager->Destroy();
}
