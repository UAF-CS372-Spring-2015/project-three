#ifndef MOVEENTITYCOMMAND_H
#define MOVEENTITYCOMMAND_H

#include "Command.h"
#include <vector>
#include <memory>

class Entity;

class MoveEntityCommand : public Command
{
public:
    MoveEntityCommand(std::vector<std::shared_ptr<Entity>>);
protected:
private:
    std::vector<std::shared_ptr<Entity>> _entities;
};

#endif // MOVEENTITYCOMMAND_H
