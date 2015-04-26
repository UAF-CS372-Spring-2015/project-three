#include "MovePlayerCommand.h"
#include "../Player.h"

#include <iostream>

MovePlayerCommand::MovePlayerCommand(Player *player): _player(player)
{
}

void MovePlayerCommand::execute(const sf::Event &event)
{
  switch(event.key.code)
  {
    case sf::Keyboard::W:
    {
      _player->setPosition(_player->getX(), _player->getY() - 5);
      std::cout << "Player moves up!" << std::endl;
      break;
    }
    case sf::Keyboard::A:
    {
      _player->setPosition(_player->getX() - 5, _player->getY());
      std::cout << "Player moves left!" << std::endl;
      break;
    }
    case sf::Keyboard::S:
    {
      _player->setPosition(_player->getX(), _player->getY() + 5);
      std::cout << "Player moves down!" << std::endl;
      break;
    }
    case sf::Keyboard::D:
    {
      _player->setPosition(_player->getX() + 5, _player->getY());
      std::cout << "Player moves right!" << std::endl;
      break;
    }
    default:
    {
      break;
    }
  }
}
