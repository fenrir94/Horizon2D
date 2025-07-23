#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
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

WindowManager& WindowManager::GetInstance()
{
	static WindowManager instance;
	return instance;
}

void WindowManager::Initialize(int width, int height, const char* title)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(width, height, title, 0, 0);
}

void WindowManager::ClearWindow()
{
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void WindowManager::CreateWindow()
{
	glfwMakeContextCurrent(m_Window);
	gladLoadGL(glfwGetProcAddress);
}

void WindowManager::SwapWindowBuffer()
{
	glfwSwapBuffers(m_Window);
}

void WindowManager::Destroy()
{
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}