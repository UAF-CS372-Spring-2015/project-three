// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// CoinRoom.h

#ifndef __THEPLATFORM_RANDOM_WALL_ROOM
#define __THEPLATFORM_RANDOM_WALL_ROOM

#include "Room.h"
#include "RoomWall.h"

class RandomWalls
{
public:
  RandomWalls() = default;
  void generateContent(Room *);
};

#endif
