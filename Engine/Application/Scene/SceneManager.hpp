#pragma once
//#include <unordered_map>
#include <Scene/Scene.hpp>
#include <list>

class SceneManager
{
public:
    static SceneManager* GetStateManager();
    void Init();
    void Update();
    void SetNextState(bool flag);
    void AddState(Scene* state);
private:
    std::string nextState;
    std::list<Scene*> states;
    std::list<Scene*>::iterator currentState;
};
