#pragma once
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include "Vector2.hpp" 

class PlatformWindow
{
public:
    bool CreateWindow() noexcept;
    void PollEvent() noexcept;
    void SwapBackBuffer() noexcept;
private:
    GLFWwindow* window = nullptr;

    int xPos = 0, yPos = 0;
    int xSize = 1600;
    int ySize = 900;
    bool isVsyncOn = true;

};