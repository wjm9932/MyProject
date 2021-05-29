#include <Object/Player.hpp>
#include <string>

Player::Player(std::string name) : Object(name)
{
}

//void Player::AddCommand(Command* cmd, std::string cmdName)
//{
//    commands.insert(std::make_pair(cmd, cmdName));
//}

//Jump* Player::GetJumpCommand()
//{
//    return jump;
//}

void Player::Jumping()
{
    std::cout << "jumping\n";
}
