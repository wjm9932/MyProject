#pragma once
#include<State/State.hpp>

class Jumping : public State
{
public:
    static Jumping* Get();
    virtual void Enter(Object* obj) override;
    virtual void Execute(Object* obj, float dtj) override;
    virtual void Exit(Object*) override;
private:
    float timer;
};