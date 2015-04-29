#ifndef __THEPLATFORMER_ROOM_H
#define __THEPLATFORMER_ROOM_H

#include "Entity.h"

class Room : public Entity
{
public:
  Room();
  Room(const double, const double);

  virtual void draw(std::shared_ptr<sf::RenderWindow>, const float) override;
	virtual sf::Vector2f getPosition() override;
	virtual void setPosition(double, double) override;

  void initializeShape();
  void setSize(double, double);
private:
  sf::RectangleShape _shape;
};

#endif
