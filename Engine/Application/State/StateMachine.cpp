#include <State/StateMachine.hpp>
#include <State/State.hpp>

StateMachine::StateMachine(Object* obj) : Component(obj)
{
    currentState = nullptr;
}

void StateMachine::Init()
{
}

void StateMachine::Update(float dt)
{
}

void StateMachine::Clear()
{
}

void StateMachine::SetCurrentState(State* state)
{
    currentState = state;
}

void StateMachine::ChangeState(State* state)
{
    currentState = state;
}
