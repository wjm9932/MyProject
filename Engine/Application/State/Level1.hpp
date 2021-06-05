#pragma once
#include <State/State.hpp>

class Achievement;
class Object;
class Level1 : public State
{
public:
    virtual void Init();
    virtual void Update();
private:
    Object* testObject_1;
    Object* testObject_2;
    Object* testObject_3;

    Achievement* test1ObjectAchievement;
    Achievement* test2ObjectAchievement;

};