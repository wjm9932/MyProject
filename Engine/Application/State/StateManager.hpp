#pragma once
//#include <unordered_map>
#include <State/State.hpp>
#include <list>

class StateManger
{
public:
    static StateManger* GetStateManager();
    void Init();
    void Update(float dt);
    void SetNextState(bool flag);
    void AddState(State* state);
private:
    std::string nextState;
    std::list<State*> states;
    std::list<State*>::iterator currentState;
};
