#include <Component/Component.hpp>
#include <Object/Object.hpp>
#include <string>

Object::Object(std::string name) : isDead(false), objName(name)
{
}

void Object::Init()
{

}

void Object::AddComponent(Component* comp)
{
    comp->Init();
    componentContainer.push_back(comp);
}

void Object::SetObjName(std::string name)
{
    objName = name;
}

void Object::SetDead(bool flag)
{
    isDead = flag;
}

bool Object::GetDead()
{
    return isDead;
}

std::string Object::GetObjectName()
{
    return objName;
}

std::vector<Component*> Object::GetComponentContainer()
{
    return componentContainer;
}
