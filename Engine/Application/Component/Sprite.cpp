#include <iostream>
#include <Component/Sprite.hpp>

Sprite::Sprite(Object* obj) : Component(obj)
{
}

void Sprite::Init()
{
    std::cout << "Component Sprite is Init\n";
}

void Sprite::Update()
{
}

void Sprite::Clear()
{
}
