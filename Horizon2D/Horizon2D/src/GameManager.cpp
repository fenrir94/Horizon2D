#include "GameManager.h"
#include <iostream>

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


void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	std::cout << "ESC" << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		
		glfwSetWindowShouldClose(window, true);
	}

	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		std::cout << "SPACE" << std::endl;
	}

}

void GameManager::Initialize(int width, int height, const char* title)
{
	m_WindowManager = &WindowManager::GetInstance();
	m_WindowManager->Initialize(width, height, title);
	m_WindowManager->CreateWindow();

	glfwSetKeyCallback(m_WindowManager->m_Window, KeyCallback);
}



void GameManager::Run()
{
	while (m_isRunning && !glfwWindowShouldClose(m_WindowManager->m_Window))
	{
		m_WindowManager->ClearWindow();

		std::cout << "Horizon" << std::endl;

		glfwPollEvents();

		m_WindowManager->SwapWindowBuffer();
	}
}

void GameManager::Destroy()
{
	m_WindowManager->Destroy();
}
