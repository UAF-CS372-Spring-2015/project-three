#ifndef __THE_PLATFORMER_GAME_H__
#define __THE_PLATFORMER_GAME_H__

#include <SFML/Graphics.hpp>
#include <memory>
#include "Command.h"
#include "GameInputHandler.h"


class Game
{
public:
  ~Game() = default;
  Game();

  std::shared_ptr<sf::RenderWindow> window();
  void exit();
  std::shared_ptr<Command> handleGameInput(sf::Event &);
private:
  std::shared_ptr<sf::RenderWindow> _window;
  GameInputHandler _gameInputHandler;
};

#endif
