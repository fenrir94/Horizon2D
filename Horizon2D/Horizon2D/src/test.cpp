#include "test.h"

void renderWindow()
{
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(640, 480, "Horizon2D", 0, 0);

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}
