#ifndef __THEPLATFORMER_COMMAND_H__
#define __THEPLATFORMER_COMMAND_H__

#include <SFML/Graphics.hpp>

class Game;

class Command
{
public:
  virtual ~Command() = default;
  virtual void execute(Game &, const sf::Event &) = 0;
private:
};

#endif
