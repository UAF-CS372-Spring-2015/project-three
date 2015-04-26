#ifndef __THEPLATFORMER_MOVE_PLAYER_COMMAND__
#define __THEPLATFORMER_MOVE_PLAYER_COMMAND__

#include "Command.h"

class Player;

class MovePlayerCommand : public Command
{
public:
  MovePlayerCommand(Player *);
  virtual void execute(const sf::Event &event) override;
private:
  Player *_player;
};

#endif
