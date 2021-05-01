#pragma once
#include <Component/Component.hpp>

class Physics : public Component
{
public:
    Physics(Object* obj);
    void Init();
    void Update();
    void Clear();
private:
};