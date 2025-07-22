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

void GameManager::Initialize()
{

}

void GameManager::Run()
{
	while (m_isRunning)
	{
		
	}
}

void GameManager::Destroy()
{
}
