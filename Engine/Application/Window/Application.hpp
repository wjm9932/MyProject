#pragma once
#include <Window/Window.hpp>

class Application
{
public:
    static Application* GetApplication();
    void Init();
    void Update(float dt);
    void Clear();

private:
    Application() = default;
    float fpsEllapsedTime = 0.f;
    int fpsFrames = 0;
    Window window;
};