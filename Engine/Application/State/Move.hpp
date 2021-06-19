#pragma once
#include<State/State.hpp>

class Object;

class Move : public State
{
public:
    static Move* Get();
    virtual void Enter(Object*) override;
    virtual void Execute(Object*) override;
    virtual void Exit(Object*) override;


private:
};