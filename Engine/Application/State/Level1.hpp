#pragma once
#include <State/State.hpp>
#include <Object/ObjectManager.hpp>

class Player;
class Object;
class Level1 : public State
{
public:
    virtual void Init();
    virtual void Update();
private:
    Player* player;
    Object* testObject_1;
    Object* testObject_2;
    Object* testObject_3;
    Object* testObject_4;

    ObjectManager* objManager = ObjectManager::GetObjectManager();
};