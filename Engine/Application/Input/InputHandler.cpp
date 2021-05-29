#include <Input/input.hpp>
#include <Input/InputHandler.hpp>

void InputHandler::Init()
{
}

void InputHandler::Update(float dt)
{
    Command* comm = GetCommand();

    if (comm != nullptr)
    {
        comm->Execute();
    }

}

InputHandler* InputHandler::GetInputHandler()
{
    static InputHandler* inputHandler = new InputHandler();
    return inputHandler;
}

void InputHandler::BindCommandToKey(Command* command, int key)
{
    const int button = GetKey(key);
    button_[button] = command;
}

Command* InputHandler::GetCommand()
{
    if (input.IsKeyTriggered(GLFW_KEY_W) == true)
    {
        return  button_[GetKey(GLFW_KEY_W)];
    }
    else
    {
        return nullptr;
    }
}

const int InputHandler::GetKey(int key)
{
    return key - OFFSET;
}
