#pragma once
#include <GLFW/glfw3.h>
#include <unordered_map>

class InputManager
{
public:
	InputManager();
	~InputManager();

	void Initialize();

	void Update(GLFWwindow* window);

	bool IsKeyPressed(int key) const;
	bool IsKeyTriggered(int key);

private:
	std::unordered_map<int, bool> m_KeyStates;
	std::unordered_map<int, bool> m_KeyTriggered;

};