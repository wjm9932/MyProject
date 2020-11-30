#include <Window/Engine.hpp>
#include  <Windows.h>

int main()
{
    Engine engine; 
 
    engine.Init(); 
 
    while (engine.GetIsRunnig() == true)
    {
        engine.Update();
    }
 
    engine.Clear(); 
 
    return 0; 
}