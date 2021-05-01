#include <State/Level1.hpp>
#include <iostream>

void Level1::Init()
{
    SetNextStateName("Level2");
    SetIsNext(false);
    std::cout << "Level1 is loaded";
}

void Level1::Update()
{

}
