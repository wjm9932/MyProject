#pragma once
#define OFFSET 52

class Command;

class InputHandler
{
public:
    static InputHandler* GetInputHandler();

    void Init();
    void Update(float dt);

    void BindCommandToKey(Command* command, int key);

    Command* GetCommand();

private:
    const int GetKey(int key); // helper func

    Command** button_ = new Command*[52];
};