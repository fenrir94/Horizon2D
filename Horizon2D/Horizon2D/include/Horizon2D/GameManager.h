#pragma once
#include "WindowManager.h"

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
	WindowManager* m_WindowManager = nullptr;
	bool m_isRunning;
};

