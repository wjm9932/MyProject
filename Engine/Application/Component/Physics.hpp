#pragma once
#include <Component/Component.hpp>
#include <Subject/Subject.hpp>
#include <vector>

class Physics : public Component, public iSubjcet
{
public:
    Physics(Object* obj);
    void Init();
    void Update(float dt);
    void Clear();

    //Observer Pattern
    virtual void AddObserver(iObserver* observer) override;
    virtual void RemoveObserver(iObserver* observer) override;

protected:
    //Observer Pattern
    virtual void Notify(float dt, Event event) override;
private:
    //Observer Pattern
    std::vector<iObserver*> mObserver;
    //test member variable for achievement
    float time = 0.f;
};