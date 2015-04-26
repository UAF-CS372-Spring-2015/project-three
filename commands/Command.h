#ifndef __THEPLATFORMER_COMMAND_H__
#define __THEPLATFORMER_COMMAND_H__

#include <SFML/Graphics.hpp>

class Command
{
public:
  virtual ~Command() = default;
  virtual void execute(bool, const sf::Event &) = 0;
private:
};

#endif
