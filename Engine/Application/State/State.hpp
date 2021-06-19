#pragma once

class Object;
class State
{
public:
    virtual void Enter(Object* obj) = 0;
    virtual void Execute(Object* obj) = 0;
    virtual void Exit(Object* ) = 0;
};