#pragma once

enum class Event;
class iObserver;

class iSubjcet
{
public:
    iSubjcet();
    ~iSubjcet();
    virtual void AddObserver(iObserver* observer) = 0;
    virtual void RemoveObserver(iObserver* observer) = 0;

protected:
    virtual void Notify(float dt, Event event) = 0;

private:
};