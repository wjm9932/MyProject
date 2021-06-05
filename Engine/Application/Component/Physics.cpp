#include <iostream>
#include <Component/Physics.hpp>
#include <Observer/Observer.hpp>
#include <algorithm>
#include <Achievement/Achievement.hpp>

Physics::Physics(Object* obj) : Component(obj)
{

}

void Physics::Init()
{
    std::cout << "Component Physics is Initialized\n";
}

void Physics::Update(float dt)
{
    time += dt;
    if (time >= 3.0)
    {
        Notify(dt, Event::SURVIVE);
        time = 0;
    }
}

void Physics::Clear()
{
}

//Observer Pattern
void Physics::AddObserver(iObserver* observer)
{
    mObserver.push_back(observer);
}

//Observer Pattern
void Physics::RemoveObserver(iObserver* observer)
{
    std::vector<iObserver* >::iterator it;

    it = std::find(mObserver.begin(), mObserver.end(), observer);
    if (it != mObserver.end())
    {
        mObserver.erase(it);
    }
}

//Observer Pattern
void Physics::Notify(float dt, Event event)
{
    for (auto it = mObserver.begin(); it != mObserver.end(); it++)
    {
        iObserver* observer = *it;
        observer->OnNotify(dt, event);
    }
}

