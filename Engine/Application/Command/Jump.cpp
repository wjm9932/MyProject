#include <iostream>
#include <Command/Jump.hpp>
#include <Object/Object.hpp>

Jump::Jump()
{
}

//Jump::Jump(Object* owner) : owner(owner)
//{
//}

//void Jump::Execute()
//{
//    Jumping();
//}

void Jump::Execute(Object& obj)
{
   
}

void Jump::Execute(Player& obj)
{
    obj.Jumping();
}


void Jump::CommandJump()
{
    //std::cout << owner->GetObjectName() << " is jumping\n";
    std::cout << "jumping\n";
}
