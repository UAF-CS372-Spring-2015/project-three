#ifndef __THEPLATFORMER_EXIT_COMMAND__
#define __THEPLATFORMER_EXIT_COMMAND__

#include "Command.h"

class ExitCommand : public Command
{
public:

  virtual void execute(Game &, const sf::Event &event) override;
};

#endif
