// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// MovePlayerCommand.cpp

#include "MovePlayerCommand.h"

MovePlayerCommand::MovePlayerCommand(Player *player): _player(player)
{
}

void MovePlayerCommand::execute(bool pressed, const sf::Event &event)
{
  // move at X pixels per second
  auto speed = 500.f;
  switch(event.key.code)
  {
    case sf::Keyboard::Up:
    case sf::Keyboard::W:
    {
      if (pressed)
      {
        _player->faceUp();
        _player->setSpeed(0.f, -speed);
      }
      else if (_player->isFacingUp())
        _player->setSpeed(0.f, 0.f);

      break;
    }
    case sf::Keyboard::Left:
    case sf::Keyboard::A:
    {
      if (pressed)
      {
        _player->faceLeft();
        _player->setSpeed(-speed, 0.f);
      }
      else if (_player->isFacingLeft())
        _player->setSpeed(0.f, 0.f);
      break;
    }
    case sf::Keyboard::Down:
    case sf::Keyboard::S:
    {
      if (pressed)
      {
        _player->faceDown();
        _player->setSpeed(0.f, speed);
      }
      else if (_player->isFacingDown())
        _player->setSpeed(0.f, 0.f);

      break;
    }
    case sf::Keyboard::Right:
    case sf::Keyboard::D:
    {
      if (pressed)
      {
        _player->faceRight();
        _player->setSpeed(speed, 0.f);
      }
      else if (_player->isFacingRight())
        _player->setSpeed(0.f, 0.f);

      break;
    }
    default:
    {
      break;
    }
  }
}
