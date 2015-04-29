#ifndef __THEPLATFORMER_EMPTY_ROOM_H__
#define __THEPLATFORMER_EMPTY_ROOM_H__

#include "Room.h"

class EmptyRoom : public Room
{
public:
  EmptyRoom();

  virtual void draw(std::shared_ptr<sf::RenderWindow>, const float) override;
	virtual sf::Vector2f getPosition() override;
	virtual void setPosition(double, double) override;

  virtual void setSize(double, double) override;
  virtual sf::Vector2f getCenter() override;
  virtual void generateContent() override;
  virtual void spawn(std::shared_ptr<Entity>, sf::Vector2f) override;

  void initializeShape();
private:
  sf::RectangleShape _shape;
  std::vector<std::shared_ptr<Entity>> _entities;
};

#endif
