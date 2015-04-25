#ifndef __THE_PLATFORMER_GAME_H__
#define __THE_PLATFORMER_GAME_H__

#include <SFML/Graphics.hpp>
#include <memory>

class Game
{
public:
  ~Game() = default;
  Game();

  std::shared_ptr<sf::RenderWindow> window();
private:
  std::shared_ptr<sf::RenderWindow> _window;
};

#endif
