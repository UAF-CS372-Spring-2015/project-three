#ifndef __THE_PLATFORMER_GAME_H__
#define __THE_PLATFORMER_GAME_H__

#include <SFML/Graphics.hpp>
#include <memory>
#include "GameInputHandler.h"
#include "Player.h"


class Game
{
public:
  ~Game() = default;
  Game();

  std::shared_ptr<sf::RenderWindow> window();
  void exit();
  void handleGameInput();
  void initializeCommands();
  bool isRunning();
  void run();
  void drawEntities();
private:

  std::shared_ptr<sf::RenderWindow> _window;
  GameInputHandler _gameInputHandler;
  Player _player;
};

#endif
