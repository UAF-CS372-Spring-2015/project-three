#ifndef __THEPLATFORMER_ROOM_WALLS_H__
#define __THEPLATFORMER_ROOM_WALLS_H__

#include "Entity.h"
#include "GameTextures.h"

class RoomWall : public Entity
{
public:
  RoomWall();
  RoomWall(double, double);

  //Implement entity methods
  virtual void draw(std::shared_ptr<sf::RenderWindow>) override;
	virtual sf::Vector2f getPosition() override;
	virtual void setPosition(double, double) override;
  virtual sf::FloatRect getGlobalBounds() override;
  virtual void update(const float &dt) override;
  virtual bool collides(std::shared_ptr<Entity>) override;
  virtual void handleCollision(Room *, Entity *) override;

  void setTexture(GameTextures *);

  void setSize(double, double);
  sf::Vector2f getSize();
  void initializeShape();

private:
  sf::RectangleShape _walls;
  std::shared_ptr<sf::Texture> _texture;
};

#endif
