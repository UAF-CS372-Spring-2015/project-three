#ifndef __THEPLATFORMER_EXIT_COMMAND__
#define __THEPLATFORMER_EXIT_COMMAND__

#include "Command.h"

class Game;

class ExitCommand : public Command
{
public:
  ExitCommand(Game *);
  virtual void execute(bool, const sf::Event &) override;
private:
  Game *_game;
};

#endif
