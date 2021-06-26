#pragma once
#include<State/State.hpp>

class Object;

class Move : public State
{
public:
    static Move* Get();
    virtual void Enter(Object*obj) override;
    virtual void Execute(Object*obj, float dt) override;
    virtual void Exit(Object*obj) override;


private:
};