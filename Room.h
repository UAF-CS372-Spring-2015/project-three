#ifndef __THEPLATFORMER_ROOM_H
#define __THEPLATFORMER_ROOM_H

#include <memory>
#include <vector>
#include <string>
#include "Entity.h"

class Room : public Entity
{
public:
  virtual void setSize(double, double) = 0;
  virtual sf::Vector2f getCenter() = 0;
  virtual void generateContent() = 0;
  virtual void spawn(std::shared_ptr<Entity>, sf::Vector2f) = 0;

};

#endif
