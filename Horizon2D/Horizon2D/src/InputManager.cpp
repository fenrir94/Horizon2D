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

	for (int key = GLFW_KEY_UNKNOWN + 1; key <= GLFW_KEY_LAST; key++)
	{
		m_KeyTriggered[key] = false;
	}
}

void InputManager::Update(GLFWwindow* window)
{
	for (int key = GLFW_KEY_UNKNOWN+1; key <= GLFW_KEY_LAST; key++)
	{
		int action = glfwGetKey(window, key);
		if (action == GLFW_PRESS)
		{
			if (!m_KeyStates[key])
			{
				m_KeyTriggered[key] = true;
			}
			m_KeyStates[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			m_KeyStates[key] = false;
			m_KeyTriggered[key] = false;
		}
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

bool InputManager::IsKeyTriggered(int key)
{
	auto iKey = m_KeyTriggered.find(key);
	if (iKey != m_KeyTriggered.end())
	{
		if (iKey->second)
		{
			bool isTriggered = true;
			m_KeyTriggered[key] = false;
			return isTriggered;
		}
		return iKey->second;
	}

	return false;
}
