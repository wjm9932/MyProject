#pragma once

class Object;

class Command
{
public:
    virtual ~Command() {};
    virtual void Execute() = 0;
    //virtual void Execute(Object& owner) = 0;
};