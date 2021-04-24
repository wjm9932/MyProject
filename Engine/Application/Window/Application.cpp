#include <iostream>
#include <Window/Application.hpp>
#include <Input/input.hpp>
#include <State/StateManager.hpp>
#include <State/TestState.hpp>
#include <State/TestState2.hpp>

Application* Application::GetApplication()
{
    static Application* app = new Application();
    return app;
}

void Application::Init()
{

    StateManger::GetStateManager()->AddState("TestState", dynamic_cast<State*>(new TestState()));
    StateManger::GetStateManager()->AddState("TestState2", dynamic_cast<State*>(new TestState2()));
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
