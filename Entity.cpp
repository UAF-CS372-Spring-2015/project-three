#include "Entity.h"

void Entity::setPosition(int x, int y)
{
  _x = x;
  _y = y;
}

int Entity::getX()
{
  return _x;
}

int Entity::getY()
{
  return _y;
}
