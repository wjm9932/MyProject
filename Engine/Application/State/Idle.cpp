#include <iostream>
#include <State/Idle.hpp>
#include <Object/Object.hpp>

Idle* Idle::Get()
{
    static Idle* state = new Idle();
    return state;
}

void Idle::Enter(Object* obj)
{
    std::cout << obj->GetObjectName() << " enter Idle State\n";
}

void Idle::Execute(Object* obj)
{
    std::cout << obj->GetObjectName() << " is on Idle State\n";
}

void Idle::Exit(Object* obj)
{
    std::cout << obj->GetObjectName() << " exit Idle State\n";
}
