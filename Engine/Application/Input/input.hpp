#pragma once
#include <bitset>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Vector2.hpp"
#include <Command/Command.hpp>
#include <Command/Jump.hpp>

class Input
{
public:
    void Init();
    void TriggeredReset();
    void SetKeyboardInput(int key, int action);
    void SetMousePos(float xPos, float yPos);
    void SetMouseButtonInput(int button, int action);
    void SetMouseWheel(double x, double y);

    bool IsKeyTriggered(int key);
    bool IsKeyPressed(int key);
    bool IsKeyReleased(int key);

    bool IsAnyKeyTriggered();

    [[nodiscard]] vector2 GetPresentMousePosition() const noexcept;
    void SetPresentMousePosition(const vector2& mousePos) noexcept;
    [[nodiscard]] vector2 GetMouseAbsolutePosition() const  noexcept;
    double MouseWheelScroll();
    bool IsMouseButtonPressed(int button);
    bool IsMouseButtonTriggered(int button);
    bool IsMouseButtonReleased(int button);
    bool IsMouseDoubleClicked(int button);

    bool IsRunning() const noexcept;
    void SetIsRunning(bool is) noexcept;

    bool GetShouldToggleWindow() const noexcept;
    void SetShouldToggleWindow(bool should) noexcept;
    void HandleInput();

private:
    std::bitset<GLFW_KEY_LAST> keyTriggered;
    std::bitset<GLFW_KEY_LAST> keyPressed;
    std::bitset<GLFW_KEY_LAST> keyReleased;

    vector2 presentMousePosition{};
    vector2 mousePosition{};
    std::bitset<GLFW_MOUSE_BUTTON_LAST> mouseButtonTriggered;
    std::bitset<GLFW_MOUSE_BUTTON_LAST> mouseButtonPressed;
    std::bitset<GLFW_MOUSE_BUTTON_LAST> mouseButtonReleased;
    std::bitset<GLFW_MOUSE_BUTTON_LAST> mouseButtonDoubleClicked;

    double xOffset = 0.0;
    double yOffset = 0.0;

    bool isRunning = true;
    bool shouldToggleWindow = false;

    Command* Button_Space = new Jump();
    Command* Button_S = nullptr;
};

extern Input input;