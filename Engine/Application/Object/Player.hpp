#pragma once
#include <Object/Object.hpp>
#include <Command/Jump.hpp>

class Player : public Object
{
public:
    Player(std::string name);
    Jump* GetJumpCommand();

private:
    Jump* jump = new Jump();
};