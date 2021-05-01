#include <State/Level2.hpp>
#include <iostream>

void Level2::Init()
{
    SetNextStateName("Level3");
    SetIsNext(false);
    std::cout << "Level2 is loaded";
}

void Level2::Update()
{

}