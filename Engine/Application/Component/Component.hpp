#pragma once
class Object;
class Component
{
public: 
    explicit Component(Object*);
    virtual void Init() = 0;
    virtual void Update(float dt) = 0;
    virtual void Clear() = 0;
protected:
    Object* owner;
};