#ifndef __THEPLATFORMER_COMMAND_H__
#define __THEPLATFORMER_COMMAND_H__

class Game;

class Command
{
public:
  virtual ~Command() = default;
  virtual void execute(Game &) = 0;
private:
};

#endif
