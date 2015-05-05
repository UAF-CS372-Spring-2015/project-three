// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// EmptyRoom.h

#ifndef EMPTY_ROOM_H
#define EMPTY_ROOM_H

#include "Room.h"

class EmptyRoom : public Room
{
public:
  EmptyRoom();
  virtual void generateContent(GameTextures *) override;
};

#endif
