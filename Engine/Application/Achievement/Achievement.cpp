#include <iostream>
#include <Achievement/Achievement.hpp>

void Achievement::Unlock(Event event)
{
    //std::cout << "You are survived! \n";
    
}

void Achievement::OnNotify(float dt, Event event)
{
    switch (event)
    {
    case Event::SURVIVE:
        Unlock(event);
        break;
    }
}
