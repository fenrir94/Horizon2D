#pragma once
#include <GLFW/glfw3.h>
#include <string>

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

	// Getters
	unsigned int GetWidthWindow();
	unsigned int GetHeightWindow();

	//Setters
	void SetWidthWindow(const unsigned int);
	void SetHeightWindow(const unsigned int);
	void SetTitleWindow(const unsigned int);

private:
	WindowManager();
	~WindowManager();

	WindowManager(const WindowManager&) = delete;
	WindowManager& operator=(const WindowManager&) = delete;

private:
	unsigned int m_width;
	unsigned int m_heigth;

	std::string title;

	GLFWwindow* m_Window = nullptr;
};