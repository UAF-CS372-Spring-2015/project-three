// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// CoinRoom.h

#ifndef COIN_ROOM_H
#define COIN_ROOM_H

#include "Room.h"

class CoinRoom : public Room
{
public:
  CoinRoom();
  virtual void generateContent() override;
};

#endif
