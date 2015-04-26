#include "MovePlayerCommand.h"
#include "../Player.h"

#include <iostream>

MovePlayerCommand::MovePlayerCommand(Player *player): _player(player)
{
}

void MovePlayerCommand::execute(const sf::Event &event)
{
  auto distance = 16;
  switch(event.key.code)
  {
    case sf::Keyboard::Up:
    case sf::Keyboard::W:
    {
      _player->faceUp();
      _player->setPosition(_player->getX(), _player->getY() - distance);
      std::cout << "Player moves up!" << std::endl;
      break;
    }
    case sf::Keyboard::Left:
    case sf::Keyboard::A:
    {
      _player->faceLeft();
      _player->setPosition(_player->getX() - distance, _player->getY());
      std::cout << "Player moves left!" << std::endl;
      break;
    }
    case sf::Keyboard::Down:
    case sf::Keyboard::S:
    {
      _player->faceDown();
      _player->setPosition(_player->getX(), _player->getY() + distance);
      std::cout << "Player moves down!" << std::endl;
      break;
    }
    case sf::Keyboard::Right:
    case sf::Keyboard::D:
    {
      _player->faceRight();
      _player->setPosition(_player->getX() + distance, _player->getY());
      std::cout << "Player moves right!" << std::endl;
      break;
    }
    default:
    {
      break;
    }
  }
}
