#pragma once
#include "WindowManager.h"

class GameManager
{
public:
	static GameManager& getInstance();

	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

	void Initialize();
	void Run();
	void Destroy();

private:
	GameManager();
	~GameManager();

private:
	WindowManager m_WindowManager;
	bool m_isRunning;
};

