// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Player.h

#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

class Player : public Entity {
public:
	Player();
	unsigned int getLives();
	virtual void draw() override;

private:
	unsigned int _lives;

};

#endif // Player_H