#include <State/StateMachine.hpp>
#include <State/State.hpp>

StateMachine::StateMachine(Object* obj) : Component(obj), currentState(nullptr)
{
}

void StateMachine::Init()
{
}

void StateMachine::Update(float dt)
{
    currentState->Execute(owner, dt);
}

void StateMachine::Clear()
{
}

void StateMachine::SetCurrentState(State* state)
{
    currentState = state;
    currentState->Enter(owner);
}

State* StateMachine::GetCurrentState()
{
    return currentState;
}

void StateMachine::ChangeState(State* state)
{
    currentState->Exit(owner);
    currentState = state;
    currentState->Enter(owner);
}
