#include <iostream>
#include <Component/Sprite.hpp>

Sprite::Sprite(Object* obj) : Component(obj)
{
}

void Sprite::Init()
{
    std::cout << "Component Sprite is Initialized\n";
}

void Sprite::Update(float dt)
{
}

void Sprite::Clear()
{
}
