#include <Object/Player.hpp>
#include <string>

Player::Player(std::string name) : Object(name)
{
}

Jump* Player::GetJumpCommand()
{
    return jump;
}