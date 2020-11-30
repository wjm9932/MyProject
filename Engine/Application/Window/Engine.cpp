#include <iostream>
#include <Window/Engine.hpp>
#include <Window/Application.hpp>
#include <Input/Input.hpp>
#include "Timer.hpp"

Application* app_ = nullptr;
void Engine::Init()
{
    app_ = Application::GetApplication();
    app_->Init();
    Timer* timer = Timer::GetTimer();
    timer->Reset();
    isRunning = true;
}

void Engine::Update()
{
    dt = static_cast<float>(Timer::GetTimer()->GetElapsedSeconds());
    Timer::GetTimer()->Reset();

    app_->Update(dt);
    if (input.IsRunning() == false)
    {
        //throw "Hello nice to meet you :)";
        isRunning = false;
    }
}

void Engine::ChangeStatus()
{
    if (isRunning == false)
        isRunning = true;
    else
        isRunning = false;
}

void Engine::Clear()
{

}