#ifndef __THEPLATFORMER_MOVE_PLAYER_COMMAND__
#define __THEPLATFORMER_MOVE_PLAYER_COMMAND__

#include "Command.h"

class MovePlayerCommand : public Command
{
public:
  virtual void execute(Game &, const sf::Event &event) override;
};

#endif
