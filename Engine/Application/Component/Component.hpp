#pragma once
class Object;
class Component
{
public: 
    explicit Component(Object*);
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Clear() = 0;
protected:
    Object* owner;
};