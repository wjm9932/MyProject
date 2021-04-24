#pragma once
class Object;
class Componet
{
public: 
    explicit Componet(Object*);
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Clear() = 0;
protected:
    Object* owner;
};