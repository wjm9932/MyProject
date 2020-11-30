#include <iostream>
#include <Window/Application.hpp>
#include <Input/input.hpp>

Application* Application::GetApplication()
{
    static Application* app = new Application();
    return app;
}

void Application::Init()
{
    input.Init();
    window.CreateWindow();
}

void Application::Update(float dt)
{
    input.TriggeredReset();

    fpsEllapsedTime += dt;
    ++fpsFrames;
    if (fpsEllapsedTime >= 1.0f)
    {
        std::cout << fpsFrames << std::endl;
        fpsEllapsedTime = 0;
        fpsFrames = 0;
    }

    window.PollEvent();
    window.SwapBackBuffer();
    GetApplication()->Input();

}

void Application::Clear()
{
}

void Application::Input()
{
    input.HandleInput();
}
