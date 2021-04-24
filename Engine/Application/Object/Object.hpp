#pragma once
#include <vector>
#include <iostream>
class Component;

class Object
{
public:
    Object();
    template <typename COMPONENT>
    COMPONENT* GetComponentByTemplate();

    void SetDead(bool flag);
    bool GetDead();
private:
    std::vector<Component*> component;
    bool isDead;
};

template<typename COMPONENT>
COMPONENT* Object::GetComponentByTemplate()
{
    for (const auto& i : component)
    {
        std::cout << typeid(i) << std::endl;
        //if (typeid(i) == typeid(COMPONENT))
        //{
        //    
        //}
    }
}
