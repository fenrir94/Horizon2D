#include "GameManager.h"
#include <iostream>
#include <GLFW/glfw3.h>	
#include <chrono>

GameManager::GameManager()
{
	m_isRunning = true;
	m_playTime = 0.f;
}

GameManager::~GameManager()
{
}

float GameManager::GetDeltaTimeMillisecond()
{
	// Set lastTime, static variable
	static auto lastTime = std::chrono::high_resolution_clock::now();

	auto currentTime = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float, std::milli> deltaTime = currentTime - lastTime;

	// Update lastTime to Current Time
	lastTime = currentTime;

	return deltaTime.count();
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
	m_RenderManager.Initialize();

	glViewport(0, 0, width, height);

}



void GameManager::Run()
{
	std::cout << "Horizon" << std::endl;

	while (m_isRunning && !glfwWindowShouldClose(m_WindowManager->m_Window))
	{
		float deltaTime = GetDeltaTimeMillisecond();
		m_playTime += deltaTime;
		m_WindowManager->ClearWindow();
		glfwPollEvents();
		
		//std::cout << m_playTime / 1000.f << std::endl;

		m_InputManager.Update(m_WindowManager->m_Window);

		// StateManager
		m_StateManager.Update(deltaTime);
		
		if (m_InputManager.IsKeyPressed(GLFW_KEY_SPACE))
		{
			//std::cout << "Space" << std::endl;
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

StateManager* GameManager::GetStateManager()
{
	return &m_StateManager;
}

InputManager* GameManager::GetInputManager()
{
	return &m_InputManager;
}

RenderManager* GameManager::GetRenderManager()
{
	return &m_RenderManager;
}
