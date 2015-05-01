// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// CoinRoom.cpp

#include "CoinRoom.h"
#include "Coin.h"
#include <memory>

CoinRoom::CoinRoom(): Room()
{
}

void CoinRoom::generateContent()
{
  for(auto ii=0; ii < 10; ++ii)
  {
    spawn(std::make_shared<Coin>(), getRandomPosition());
  }
}
