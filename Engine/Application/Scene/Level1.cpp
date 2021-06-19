//system
#include <iostream>

//Application
#include <Scene/Level1.hpp>
#include <Object/Object.hpp>
#include <Object/ObjectManager.hpp>
#include <Component/Physics.hpp>
#include <Component/Sprite.hpp>
#include <Input/input.hpp>
#include <Achievement/Achievement.hpp>

//State
#include <State/StateMachine.hpp>
#include <State/Idle.hpp>
#include <State/Move.hpp>
void Level1::Init()
{
    SetIsNext(false);
    std::cout << "Level1 is loaded\n";


    test1ObjectAchievement = new Achievement();
    test2ObjectAchievement = new Achievement();

    auto objManager = ObjectManager::GetObjectManager();
    
    testObject_1 = new Object("testObject_1");
    testObject_1->AddComponent(new Physics(testObject_1));
    testObject_1->AddComponent(new Sprite(testObject_1));
    testObject_1->AddComponent(new StateMachine(testObject_1));

    testObject_2 = new Object("testObject_2");
    testObject_2->AddComponent(new Sprite(testObject_2));
    testObject_2->AddComponent(new Physics(testObject_2));
    testObject_2->GetComponentByTemplate<Physics>()->AddObserver(test2ObjectAchievement);

    testObject_3 = new Object("testObject_3");
    testObject_3->AddComponent(new Physics(testObject_3));
    testObject_3->AddComponent(new Sprite(testObject_3));

    objManager->AddObject(testObject_1);
    objManager->AddObject(testObject_2);
    objManager->AddObject(testObject_3);

    testObject_1->GetComponentByTemplate<Physics>()->AddObserver(test1ObjectAchievement);
    testObject_1->GetComponentByTemplate<StateMachine>()->SetCurrentState(Idle::Get());
}

void Level1::Update()
{
    if (input.IsKeyTriggered(GLFW_KEY_1))
    {
        testObject_1->SetDead(true);
    }
    if (input.IsKeyTriggered(GLFW_KEY_2))
    {
        testObject_2->SetDead(true);
    }
    if (input.IsKeyTriggered(GLFW_KEY_3))
    {
        testObject_3->SetDead(true);

    }
    if (input.IsKeyTriggered(GLFW_KEY_4))
    {
        testObject_1->GetComponentByTemplate<Physics>()->RemoveObserver(test1ObjectAchievement);
    }
    if (input.IsKeyPressed(GLFW_KEY_W))
    {
        testObject_1->GetComponentByTemplate<StateMachine>()->ChangeState(Move::Get());
    }
    if (input.IsKeyReleased(GLFW_KEY_W))
    {
        testObject_1->GetComponentByTemplate<StateMachine>()->ChangeState(Idle::Get());
    }
}
