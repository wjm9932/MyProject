#pragma once
#include <Component/Component.hpp>

class State;
class Object;

class StateMachine : public Component
{
public:
    StateMachine(Object*);

    virtual void Init() override;
    virtual void Update(float dt) override;
    virtual void Clear() override;

    void ChangeState(State* state);

    void SetCurrentState(State* state);
    State* GetCurrentState();

private:
    State* currentState;
};