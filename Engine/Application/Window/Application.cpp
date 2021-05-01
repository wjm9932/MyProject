#include <iostream>
#include <Window/Application.hpp>
#include <Input/input.hpp>
#include <State/StateManager.hpp>
#include <State/Level1.hpp>
#include <State/Level2.hpp>

Application* Application::GetApplication()
{
    static Application* app = new Application();
    return app;
}

void Application::Init()
{

    StateManger::GetStateManager()->AddState(dynamic_cast<State*>(new Level1()));
    StateManger::GetStateManager()->AddState(dynamic_cast<State*>(new Level2()));
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

    const auto& stateManger = StateManger::GetStateManager();
    stateManger->Update();

    GetApplication()->Input();

}

void Application::Clear()
{
}

void Application::Input()
{
    input.HandleInput();
}
