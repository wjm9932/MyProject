#include <iostream>
#include <State/Jumping.hpp>
#include <Object/Object.hpp>
#include <State/StateMachine.hpp>
#include <State/Idle.hpp>
Jumping* Jumping::Get()
{
    static Jumping* jump = new Jumping();
    return jump;
}

void Jumping::Enter(Object* obj)
{
    std::cout << obj->GetObjectName() << " enter Jumping State\n";
    timer = 0.f;
}

void Jumping::Execute(Object* obj,float dt)
{
    std::cout << obj->GetObjectName() << " is on Jumping State\n";
    timer += dt;
    if (timer >= 3.f)
    {
        obj->GetComponentByTemplate<StateMachine>()->ChangeState(Idle::Get());
    }
}

void Jumping::Exit(Object* obj)
{
    std::cout << obj->GetObjectName() << " exit Jumping State\n";
}
