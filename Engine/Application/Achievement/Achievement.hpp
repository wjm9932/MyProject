#pragma once
#include <Observer/Observer.hpp>

enum  class Event
{
    SURVIVE,
    DEAD
};

class Achievement : public iObserver
{
public:

    void Unlock(Event event);
    //Observer Pattern
    virtual void OnNotify(float dt, Event event) override;
    
private:
};