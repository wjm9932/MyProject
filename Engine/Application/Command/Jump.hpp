#pragma once
#include <Command/Command.hpp>
#include <Object/Object.hpp>
#include <Object/Player.hpp>
class Object;

class Jump : public Command
{
public:
    //virtual void Execute();
    virtual void Execute(Object& obj);
    virtual void Execute(Player& obj);
private:
    //Object* owner;
};