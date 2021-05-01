#pragma once
#include <string>

class State
{
public:
    virtual void Init() = 0;
    virtual void Update() = 0;
    bool GetIsNext();
    void SetIsNext(bool flag);
private:
    bool isNext;
};