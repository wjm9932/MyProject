#pragma once
#include <vector>
#include <memory>
class Object;

class ObjectManager
{
public:
    static ObjectManager* GetObjectManager();
    void AddObject(Object* obj);
    void Update();

private:
    std::vector<Object* > objectContainer;
    std::vector<Object*> toBeDeletedObj{};

    void DeleteObject(Object* obj);
};