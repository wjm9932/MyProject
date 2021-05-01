#pragma once
#include <vector>
#include <iostream>

class Component;

class Object
{
public:
    Object(std::string name);
    template <typename COMPONENT>
    COMPONENT* GetComponentByTemplate();
    
    void Init();
    void AddComponent(Component* comp);
    void SetObjName(std::string name);
    void SetDead(bool flag);
    bool GetDead();
    std::string GetObjectName();
    std::vector<Component*> GetComponentContainer();

private:
    std::string objName;
    std::vector<Component*> componentContainer;
    bool isDead;
};

template<typename COMPONENT>
COMPONENT* Object::GetComponentByTemplate()
{
    for (const auto& i : componentContainer)
    {
        COMPONENT* iterator = dynamic_cast<COMPONENT*>(i);
        if (iterator != nullptr)
        {
            if (typeid(COMPONENT*) == typeid(iterator))
            {
                return iterator;
            }
        }
    }
    return nullptr;
}
