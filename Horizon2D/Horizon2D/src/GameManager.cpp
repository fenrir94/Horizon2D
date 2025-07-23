#include "GameManager.h"

GameManager::GameManager()
{
	m_isRunning = true;
}

GameManager::~GameManager()
{
}

GameManager& GameManager::getInstance()
{
	static GameManager instance;
	return instance;
}

void GameManager::Initialize(int width, int height, const char* title)
{
	m_WindowManager = &WindowManager::getInstance();
	m_WindowManager->Initialize(width, height, title);
	m_WindowManager->CreateWindow();
}

void GameManager::Run()
{
	
	while (m_isRunning)
	{
		m_WindowManager->ClearWindow();
	}
}

void GameManager::Destroy()
{
	m_WindowManager->Destroy();
}
