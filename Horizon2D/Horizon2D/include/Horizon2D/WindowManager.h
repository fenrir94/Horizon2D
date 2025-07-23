#pragma once
#include <GLFW/glfw3.h>

class GameManager;

class WindowManager
{
	friend GameManager;
public:
	static WindowManager& GetInstance();

	void Initialize(int widht, int height, const char* title);
	void ClearWindow();
	void CreateWindow();
	void SwapWindowBuffer();
	void Destroy();

private:
	WindowManager();
	~WindowManager();

	WindowManager(const WindowManager&) = delete;
	WindowManager& operator=(const WindowManager&) = delete;

private:
	unsigned int m_width;
	unsigned int m_heigth;

	GLFWwindow* m_Window = nullptr;
};

