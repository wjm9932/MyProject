#pragma once
#include <Object/Object.hpp>
#include <Command/Jump.hpp>
//#include <Command/Command.hpp>
#include <unordered_map>

class Player : public Object
{
public:
    Player(std::string name);
    //void AddCommand(Command* cmd, std::string cmdName);
    //Jump* GetJumpCommand();
    void Jumping();
private:
    //Jump* jump = new Jump();
    //std::unordered_map<Command*, std::string> commands;
};