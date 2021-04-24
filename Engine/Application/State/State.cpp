#include "State.hpp"

bool State::GetIsNext()
{
    return isNext;
}

void State::SetIsNext(bool flag)
{
    isNext = flag;
}

std::string State::GetNextStateName()
{
    return nextStateName;
}

void State::SetNextStateName(std::string name)
{
    nextStateName = name;
}
