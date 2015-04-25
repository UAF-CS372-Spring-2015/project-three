#ifndef __THEPLATFORMER_NULL_COMMAND
#define __THEPLATFORMER_NULL_COMMAND

#include "Command.h"

class NullCommand : public Command
{
public:
  virtual void execute(const sf::Event &) override;
};

#endif
