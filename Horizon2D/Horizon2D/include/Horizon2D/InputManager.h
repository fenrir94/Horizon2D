#pragma once
#include <GLFW/glfw3.h>

class InputManager
{
public:
	InputManager();
	~InputManager();

	void Initialize();
	void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
	

};

