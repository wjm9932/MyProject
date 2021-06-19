#include <iostream>
#include <State/Move.hpp>
#include <Object/Object.hpp>

Move* Move::Get()
{
    static Move* state = new Move();
    return state;
}

void Move::Enter(Object* obj)
{
    std::cout << obj->GetObjectName() << " enter Move State\n";
}

void Move::Execute(Object* obj)
{
    std::cout << obj->GetObjectName() << " is on Move State\n";
}

void Move::Exit(Object* obj)
{
    std::cout << obj->GetObjectName() << " exit Move State\n";
}
