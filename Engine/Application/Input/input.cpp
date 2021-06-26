#include <chrono>
#include "input.hpp"
#include <Window/PlatformWindow.hpp>
#include <iostream>

Input input;

void Input::Init()
{
    xOffset = 0.0;
    yOffset = 0.0;

    keyPressed.reset();
    keyReleased.set();
    keyTriggered.reset();
}

void Input::TriggeredReset()
{
    keyTriggered.reset();
    mouseButtonDoubleClicked.reset();
    mouseButtonTriggered.reset();

    xOffset = 0;
    yOffset = 0;
}

void Input::SetKeyboardInput(int key, int action)
{
    if (key >= GLFW_KEY_LAST || key < 0)
    {
        return;
    }
    switch (action)
    {
    case GLFW_PRESS:
    {
        keyPressed.set(key);
        keyTriggered.set(key);
        keyReleased.reset(key);
        break;
    }
    case GLFW_RELEASE:
    {
        keyPressed.reset(key);
        keyTriggered.reset(key);
        keyReleased.set(key);
        break;
    }
    default:
        break;
    }
}

void Input::SetMouseButtonInput(int button, int action)
{
    switch (action)
    {
    case GLFW_PRESS:
        mouseButtonPressed.set(button);
        mouseButtonReleased.reset(button);
        mouseButtonTriggered.set(button);
        break;
    case GLFW_RELEASE:
    {
        static auto before = std::chrono::system_clock::now();
        auto now = std::chrono::system_clock::now();
        double diffMs = std::chrono::duration<double, std::milli>(now - before).count();
        before = now;
        if (diffMs > 10 && diffMs < 200)
        {
            mouseButtonDoubleClicked.set(button);
        }
        else
        {
            mouseButtonDoubleClicked.reset(button);
        }
        mouseButtonPressed.reset(button);
        mouseButtonReleased.set(button);
        mouseButtonTriggered.reset(button);
        break;
    }
    default:
        break;
    }
}

void Input::SetMouseWheel(double x, double y)
{
    xOffset = x;
    yOffset = y;
}

bool Input::IsKeyTriggered(int key)
{
    return keyTriggered[key];
}

bool Input::IsKeyPressed(int key)
{
    return keyPressed[key];
}

bool Input::IsKeyReleased(int key)
{
    return keyReleased[key];
}

bool Input::IsAnyKeyTriggered()
{
    return keyTriggered.any();
}

vector2 Input::GetPresentMousePosition() const noexcept
{
    return presentMousePosition;
}

void Input::SetPresentMousePosition(const vector2& mousePos) noexcept
{
    presentMousePosition = mousePos;
}

vector2 Input::GetMouseAbsolutePosition() const noexcept
{
    return mousePosition;
}


bool Input::IsMouseButtonTriggered(int button)
{
    return mouseButtonTriggered[button];
}

bool Input::IsMouseButtonPressed(int button)
{
    return mouseButtonPressed[button];
}

bool Input::IsMouseButtonReleased(int button)
{
    return mouseButtonReleased[button];
}

bool Input::IsMouseDoubleClicked(int button)
{
    return mouseButtonDoubleClicked[button];
}

bool Input::IsRunning() const noexcept
{
    return isRunning;
}

void Input::SetIsRunning(bool is) noexcept
{
    isRunning = is;
}

bool Input::GetShouldToggleWindow() const noexcept
{
    return shouldToggleWindow;
}

void Input::SetShouldToggleWindow(bool should) noexcept
{
    shouldToggleWindow = should;
}

void Input::HandleInput()
{
  
}

double Input::MouseWheelScroll()
{
    return yOffset;
}

void Input::SetMousePos(float xPos, float yPos)
{
    //float x = Application::GetApplication()->GetWindowSize.x;
    //float y = Application::GetApplication()->GetWindowSize.y;

    //mousePosition.x = -(x / 2.0f - xPos);
    //mousePosition.y = y / 2.0f - yPos;
}