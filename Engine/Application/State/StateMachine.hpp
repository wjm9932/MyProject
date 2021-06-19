#pragma once
#include <Component/Component.hpp>

class State;

class StateMachine : public Component
{
public:
    StateMachine(Object*);
    virtual void Init() override;
    virtual void Update(float dt) override;
    virtual void Clear() override;

    void SetCurrentState(State* state);
    void ChangeState(State* state);

private:
    State* currentState;
};