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
	//glfwSetWindowUserPointer(m_Window, this);
	for (int key = GLFW_KEY_UNKNOWN + 1; key <= GLFW_KEY_LAST; key++)
	{
		m_KeyStates[key] = false;
	}
}

void InputManager::Update(GLFWwindow* window)
{
	for (int key = GLFW_KEY_UNKNOWN+1; key <= GLFW_KEY_LAST; key++)
	{
		int state = glfwGetKey(window, key);
		m_KeyStates[key] = (state == GLFW_PRESS || state == GLFW_REPEAT);
	}
}

bool InputManager::IsKeyPressed(int key) const
{
	auto iKey = m_KeyStates.find(key);
	if (iKey != m_KeyStates.end())
	{
		return iKey->second;
	}

	return false;
}
