#include <iostream>
#include <State/Idle.hpp>
#include <Object/Object.hpp>
#include <Input/input.hpp>
#include <State/StateMachine.hpp>
#include <State/Jumping.hpp>
#include <State/Move.hpp>

Idle* Idle::Get()
{
    static Idle* state = new Idle();
    return state;
}

void Idle::Enter(Object* obj)
{
    std::cout << obj->GetObjectName() << " enter Idle State\n";
}

void Idle::Execute(Object* obj,float dt)
{
    std::cout << obj->GetObjectName() << " is on Idle State\n";

    if (input.IsKeyPressed(GLFW_KEY_W))
    {
        obj->GetComponentByTemplate<StateMachine>()->ChangeState(Move::Get());
    }
    if (input.IsKeyTriggered(GLFW_KEY_SPACE))
    {
        obj->GetComponentByTemplate<StateMachine>()->ChangeState(Jumping::Get());
    }
}

void Idle::Exit(Object* obj)
{
    std::cout << obj->GetObjectName() << " exit Idle State\n";
}
