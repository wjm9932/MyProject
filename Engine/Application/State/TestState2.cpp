#include <State/TestState2.hpp>
#include <iostream>

void TestState2::Init()
{
    SetNextStateName("TestLevel3");
    SetIsNext(false);
    std::cout << "Test State2 is loaded";
}

void TestState2::Update()
{

}