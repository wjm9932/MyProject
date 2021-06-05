#pragma once
enum class Event;
class iObserver
{
public:
    iObserver();
    ~iObserver();
    virtual void OnNotify(float dt, Event event) = 0;
private:
};