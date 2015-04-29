#ifndef __THEPLATFORMER_ROOM_H
#define __THEPLATFORMER_ROOM_H

#include <memory>
#include <vector>
#include <string>
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
  sf::Vector2f getCenter();
  void spawn(std::shared_ptr<Entity>, sf::Vector2f);
  void spawn(std::string, sf::Vector2f);
  void generateContent();
private:
  sf::RectangleShape _shape;
  std::vector<std::shared_ptr<Entity>> _entities;
};

#endif
