#include "WindowManager.h"
#include "Constants.h"



WindowManager::WindowManager()
{
	m_width = Horizon2D::WINDOW_WIDTH;
	m_heigth = Horizon2D::WINDOW_HIGHT;
}

WindowManager::~WindowManager()
{
}

WindowManager& WindowManager::getInstance()
{
	static WindowManager instance;
	return instance;
}

void WindowManager::Initialize(int width, int height, const char* title)
{
	glfwInit();
	m_Window = glfwCreateWindow(width, height, title, 0, 0);
}

void WindowManager::ClearWindow()
{
	glClearColor(1.f, 1.f, 1.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(m_Window);
}

void WindowManager::CreateWindow()
{
	glfwMakeContextCurrent(m_Window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

void WindowManager::Destroy()
{
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}