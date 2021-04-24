#include <State/TestState.hpp>
#include <iostream>

void TestState::Init()
{
    SetNextStateName("TestState2");
    SetIsNext(false);
    std::cout << "Test State is loaded";
}

void TestState::Update()
{

}
