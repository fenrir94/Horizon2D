#include "InputManager.h"
#include <iostream>

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::Initialize()
{
	glfwSetKeyCallback(m_Window, KeyCallback);
}

void InputManager::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		std::cout << "ESC" << std::endl;
		glfwSetWindowShouldClose(window, true);
	}

	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		std::cout << "SPACE" << std::endl;
	}
}