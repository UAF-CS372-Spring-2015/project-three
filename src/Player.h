// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Room.h"
#include "Coin.h"
#include <memory> // for shared_ptr

#define PLAYER_FACE_DOWN sf::IntRect(0, 0, 32, 32)
#define PLAYER_FACE_LEFT sf::IntRect(0, 33, 32, 32)
#define PLAYER_FACE_RIGHT sf::IntRect(0, 65, 32, 32)
#define PLAYER_FACE_UP sf::IntRect(0, 97, 32, 32)

class Player : public Entity {
public:
	Player();
	unsigned int getLives();
	virtual void draw(std::shared_ptr<sf::RenderWindow>) override;
	virtual sf::Vector2f getPosition() override;
	virtual void setPosition(double, double) override;
	virtual sf::FloatRect getGlobalBounds() override;
	virtual bool collides(std::shared_ptr<Entity>) override;
	virtual void update(const float &) override;
	virtual void handleCollision(Room *) override;
	virtual void handleCollision(Room *, Coin *) override;

	void faceLeft();
	void faceRight();
	void faceUp();
	void faceDown();
	bool isFacingUp();
	bool isFacingDown();
	bool isFacingLeft();
	bool isFacingRight();
	bool isFacing(sf::IntRect);

	sf::Vector2f getSpeed();
	void setSpeed(double, double);
private:
	unsigned int _lives;
	sf::IntRect _facing;
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _speed;
	sf::Vector2f _previousPosition;

};

#endif
