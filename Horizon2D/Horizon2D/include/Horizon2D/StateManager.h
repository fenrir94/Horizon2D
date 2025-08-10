#pragma once
#include "IGameState.h"
#include <memory>
#include <functional>
#include <string>
#include <unordered_map>
#include <Object.h>

class StateManager
{
public:
	using StateFactory = std::function<std::unique_ptr<IGameState>()>;

	StateManager();
	~StateManager();

	void RegisterState(const std::string& name, StateFactory factory);
	void ChangeGameState(const std::string& name);

	void Initialize(const std::string& name);
	void Update(float dt);
	
	void ContainObject(Object* obj);
	
	std::vector<Object>& GetObjects();


private:
	std::unordered_map<std::string, StateFactory> m_StateFactories;
	std::unique_ptr<IGameState> m_GameStateCurrent;
	std::string m_GameStateNextStr;

	std::vector<Object> m_Objects;

};

