#ifndef __THE_PLATFORMER_GAME_H__
#define __THE_PLATFORMER_GAME_H__

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "GameInputHandler.h"
#include "Player.h"
#include "Coin.h"
#include "Room.h"


class Game
{
public:
  ~Game() = default;
  Game();

  std::shared_ptr<sf::RenderWindow> window();
  void exit();
  void handleEvents();
  void initializeCommands();
  bool isRunning();
  void run();
  void drawEntities(float);
private:

  Coin _coins;
  std::shared_ptr<sf::RenderWindow> _window;
  GameInputHandler _gameInputHandler;
  Player _player;

  Room _currentRoom;

};

#endif
