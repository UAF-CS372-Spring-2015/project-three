// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Entity.cpp

#include "Entity.h"
#include "Room.h"
#include "Coin.h"
#include <iostream>

// Default implementations for collisions
// Derived classes should override this if they need to respond to this type of
//    collision
void Entity::handleCollision(Room *room)
{
}

void Entity::handleCollision(Coin *coin)
{
}
