#include <iostream>
#include <Component/Physics.hpp>

Physics::Physics(Object* obj) : Component(obj)
{

}

void Physics::Init()
{
    std::cout << "Component Physics is Init\n";
}

void Physics::Update()
{
}

void Physics::Clear()
{
}

