#include <Input/input.hpp>
#include <Input/InputHandler.hpp>

void InputHandler::Init()
{
}

void InputHandler::Update(float dt)
{
    if (input.IsKeyTriggered(GLFW_KEY_W) == true)
    {
        button_[GetButton(GLFW_KEY_W)]->Execute();
    }
}

InputHandler* InputHandler::GetInputHandler()
{
    static InputHandler* inputHandler = new InputHandler();
    return inputHandler;
}

void InputHandler::BindCommandToKey(Command* command, int key)
{
    const int button = GetButton(key);
    button_[button] = command;
}

const int InputHandler::GetButton(int key)
{
    return key - OFFSET;
}
