#define UNUSED

#include <Window/PlatformWindow.hpp>
#include <Input/input.hpp>

namespace
{
    
    void KeyCallback(GLFWwindow*, int key, int scancode, int action, int)
    {
        UNUSED(scancode);
        input.SetKeyboardInput(key, action);
    }

    void MousePosCallback(GLFWwindow* window, double xPos, double yPos)
    {
        input.SetMousePos(static_cast<float>(xPos), static_cast<float>(yPos));
    }
}



bool PlatformWindow::CreateWindow() noexcept
{
    if (!glfwInit())
    {
        return false;
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    window = glfwCreateWindow(800, 600, "engine", nullptr, nullptr);

    if (!window)
    {
        return false;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(true);
    glfwSetKeyCallback(window, KeyCallback);

    return true;
}

void PlatformWindow::PollEvent() noexcept
{
    glfwPollEvents();
}

void PlatformWindow::SwapBackBuffer() noexcept
{
    glfwSwapBuffers(window);
}
