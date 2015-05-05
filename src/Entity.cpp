// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Entity.cpp

#include "Entity.h"
#include "Room.h"
#include "Coin.h"
#include "Player.h"
#include "RoomWall.h"
#include <iostream>

// Default implementations for collisions
// Derived classes should override this if they need to respond to this type of
//    collision
void Entity::handleCollision(Room *room)
{
}

void Entity::handleCollision(Room *room, Coin *coin)
{
}

void Entity::handleCollision(Room *room, Player *player)
{
}

void Entity::handleCollision(Room *room, RoomWall *wall)
{
}

// You will need to implement a "double dispatch" method in each entity to pass in the 
void Entity::handleCollision(Room *room, Entity *entity)
{
  // entity->handleCollision(room, this);
}
