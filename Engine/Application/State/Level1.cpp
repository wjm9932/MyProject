#include <State/Level1.hpp>
#include <iostream>
#include <Object/Object.hpp>
#include <Object/ObjectManager.hpp>
#include <Component/Physics.hpp>
#include <Component/Sprite.hpp>
#include <Input/input.hpp>

void Level1::Init()
{
    SetIsNext(false);
    std::cout << "Level1 is loaded\n";

    auto objManager = ObjectManager::GetObjectManager();
    
    testObject_1 = new Object("testObject_1");
    testObject_1->AddComponent(new Physics(testObject_1));
    testObject_1->AddComponent(new Sprite(testObject_1));

    testObject_2 = new Object("testObject_2");
    testObject_2->AddComponent(new Sprite(testObject_2));
    testObject_2->AddComponent(new Physics(testObject_2));

    testObject_3 = new Object("testObject_3");
    testObject_3->AddComponent(new Physics(testObject_3));
    testObject_3->AddComponent(new Sprite(testObject_3));

    objManager->AddObject(testObject_1);
    objManager->AddObject(testObject_2);
    objManager->AddObject(testObject_3);
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
}
