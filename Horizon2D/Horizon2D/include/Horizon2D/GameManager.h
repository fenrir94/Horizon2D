#pragma once
#include "WindowManager.h"
#include "InputManager.h"

class GameManager
{
public:
	static GameManager& GetInstance();

	void Initialize(int width, int height, const char* title);
	void Run();
	void Destroy();

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
	bool m_isRunning;
};

