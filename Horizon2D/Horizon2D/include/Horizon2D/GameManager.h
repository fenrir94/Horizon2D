#pragma once
#include "WindowManager.h"
#include "InputManager.h"
#include "StateManager.h"
#include "RenderManager.h"

class GameManager
{
public:
	static GameManager& GetInstance();

	void Initialize(int width, int height, const char* title);
	void Run();
	void Destroy();

	// 
	StateManager* GetStateManager();
	InputManager* GetInputManager();
	RenderManager* GetRenderManager();

private:
	GameManager();
	~GameManager();

	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

private:
	// Singleton
	WindowManager* m_WindowManager = nullptr;
	
	// 
	InputManager m_InputManager;
	StateManager m_StateManager;
	RenderManager m_RenderManager;
	
	bool m_isRunning;
};

