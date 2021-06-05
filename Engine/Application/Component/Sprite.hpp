#pragma once
#include <Component/Component.hpp>

class Object;
class Sprite : public Component
{
public:
    Sprite(Object* obj);
    void Init();
    void Update(float dt);
    void Clear();
private:
};