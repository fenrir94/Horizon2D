#include "StateManager.h"
#include <iostream>

StateManager::StateManager()
{
	m_GameStateNextStr = "";
}

StateManager::~StateManager()
{
}

void StateManager::Initialize(const std::string& name)
{
	ChangeGameState(name);
}

void StateManager::Update()
{
	float dt = 0;
	
	auto iStateFactory = m_StateFactories.find(m_GameStateNextStr);

	if(iStateFactory != m_StateFactories.end())
	{
		if (m_GameStateCurrent)
		{
			m_GameStateCurrent->Exit();
		}
		m_GameStateCurrent = iStateFactory->second();
		std::cout << "Change" << std::endl;
		m_GameStateCurrent->Initialize();
		m_GameStateNextStr = "";
	}
	m_GameStateCurrent->Update(dt);
}

void StateManager::ChangeGameState(const std::string& name)
{
	m_GameStateNextStr = name;
}

void StateManager::RegisterState(const std::string& name, StateFactory factory)
{
	std::cout << "Register" << std::endl;
	m_StateFactories[name] = std::move(factory);
}
