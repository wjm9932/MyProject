#include <iostream>
#include <Window/Application.hpp>
#include <Input/input.hpp>
#include <Scene/SceneManager.hpp>
#include <Object/ObjectManager.hpp>
#include <Scene/Level1.hpp>
#include <Scene/Level2.hpp>

Application* Application::GetApplication()
{
    static Application* app = new Application();
    return app;
}

void Application::Init()
{

    SceneManager::GetStateManager()->AddState(dynamic_cast<Scene*>(new Level1()));
    SceneManager::GetStateManager()->AddState(dynamic_cast<Scene*>(new Level2()));
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

    const auto& stateManger = SceneManager::GetStateManager();
    stateManger->Update();
    const auto& objManager = ObjectManager::GetObjectManager();
    objManager->Update(dt);

    GetApplication()->Input();

}

void Application::Clear()
{
}

void Application::Input()
{
    input.HandleInput();
}
