#include <string>
#include <State/StateManager.hpp>
#include <Input/input.hpp>

StateManger* StateManger::GetStateManager()
{
    static StateManger* stateManager = new StateManger();
    return stateManager;
}

void StateManger::Init()
{
}

void StateManger::Update()
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

void StateManger::SetNextState(bool flag)
{
    (*currentState)->SetIsNext(flag);
}

void StateManger::AddState(State* state)
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


