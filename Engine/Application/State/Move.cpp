#include <iostream>
#include <State/Move.hpp>
#include <Object/Object.hpp>
#include <Input/input.hpp>
#include <State/StateMachine.hpp>
#include <State/Idle.hpp>

Move* Move::Get()
{
    static Move* state = new Move();
    return state;
}

void Move::Enter(Object* obj)
{
    std::cout << obj->GetObjectName() << " enter Move State\n";
}

void Move::Execute(Object* obj, float dt)
{
    std::cout << obj->GetObjectName() << " is on Move State\n";
    if (input.IsKeyReleased(GLFW_KEY_W))
    {
        obj->GetComponentByTemplate<StateMachine>()->ChangeState(Idle::Get());
    }
}

void Move::Exit(Object* obj)
{
    std::cout << obj->GetObjectName() << " exit Move State\n";
}
