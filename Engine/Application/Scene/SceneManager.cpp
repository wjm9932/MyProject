#include <string>
#include <Scene/SceneManager.hpp>
#include <Input/input.hpp>

SceneManager* SceneManager::GetStateManager()
{
    static SceneManager* stateManager = new SceneManager();
    return stateManager;
}

void SceneManager::Init()
{
}

void SceneManager::Update()
{
    if (input.IsKeyTriggered(GLFW_KEY_N))
    {
        SetNextState(true);
    }
    (*currentState)->Update();

    if ((*currentState)->GetIsNext() == true)
    {

        currentState++;
        (*currentState)->Init();
    }
}

void SceneManager::SetNextState(bool flag)
{
    (*currentState)->SetIsNext(flag);
}

void SceneManager::AddState(Scene* state)
{
    if (states.empty() == true)
    {
        states.push_back(state);
        currentState = states.begin();
        (*currentState)->Init();
    }
    else
    {
        states.push_back(state);
    }

}


