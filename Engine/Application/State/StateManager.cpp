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
        SetNextState();
    }
    currentState->Update();

    if (currentState->GetIsNext() == true)
    {
        std::string tmpName = currentState->GetNextStateName();
        const auto& temp = states.find(tmpName);
        currentState = temp->second;
        
        currentState->Init();
    }
}

void StateManger::SetNextState()
{
    currentState->SetIsNext(true);

}

void StateManger::AddState(std::string name, State* state)
{
    auto tmp = std::make_pair(name, state);
    if (currentState == nullptr)
    {
        currentState = state;
        currentState->Init();
    }

    states.insert(tmp);

}


