#pragma once
#include <unordered_map>
#include <State/State.hpp>

class StateManger
{
public:
    static StateManger* GetStateManager();
    void Init();
    void Update();
    void SetNextState();
    void AddState(std::string, State* state);
private:
    std::string nextState;
    std::unordered_map<std::string, State*> states;
    State* currentState = nullptr;
};
