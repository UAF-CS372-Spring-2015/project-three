#include "MovePlayerCommand.h"
#include <iostream>

void MovePlayerCommand::execute(const sf::Event &event)
{
  switch(event.key.code)
  {
    case sf::Keyboard::W:
      std::cout << "Player moves up!" << std::endl;
      break;
    case sf::Keyboard::A:
      std::cout << "Player moves left!" << std::endl;
      break;
    case sf::Keyboard::S:
      std::cout << "Player moves down!" << std::endl;
      break;
    case sf::Keyboard::D:
      std::cout << "Player moves right!" << std::endl;
      break;
  }
}
