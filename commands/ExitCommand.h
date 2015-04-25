#ifndef __THEPLATFORMER_EXIT_COMMAND__
#define __THEPLATFORMER_EXIT_COMMAND__

#include "Command.h"

class Game;

class ExitCommand : public Command
{
public:
  ExitCommand(Game *);
  virtual void execute(const sf::Event &event) override;
private:
  Game *_game;
};

#endif
