#pragma once

class Application;

class Engine
{
public:
    Engine() = default;

    void Init();
    void Update();
    void Clear();

    bool GetIsRunnig() noexcept
    {
        return isRunning;
    }

    void ChangeStatus();

private:
    float timea = 0;
    bool isRunning = false;
    float dt = 0;
};