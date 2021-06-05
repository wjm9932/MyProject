#include <Object/ObjectManager.hpp>
#include <Object/Object.hpp>
#include <Component/Component.hpp>

ObjectManager* ObjectManager::GetObjectManager()
{
    static ObjectManager* objectManager = new ObjectManager();
    return objectManager;
}

void ObjectManager::AddObject(Object* obj)
{
    obj->Init();
    objectContainer.push_back(obj);
}

void ObjectManager::Update(float dt)
{
    toBeDeletedObj.clear();
    for (const auto& obj : objectContainer)
    {
        if (obj->GetDead() == true)
        {
            toBeDeletedObj.push_back(obj);
            continue;
        }
        for (const auto& comp : obj->GetComponentContainer())
        {
            comp->Update(dt);
        }
    }
    for (const auto& obj : toBeDeletedObj)
    {
        DeleteObject(obj);
    }
}

void ObjectManager::DeleteObject(Object* obj)
{
    for (auto it = objectContainer.begin(); it != objectContainer.end();)
    {
        if (*it == obj)
        {
            std::cout << (*it)->GetObjectName() << " is deleted\n";
            it = objectContainer.erase(it);
        }
        else
        {
            ++it;
        }
    }
}


