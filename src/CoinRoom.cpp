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
  auto pos = getCenter();

  for(auto ii=0; ii < 10; ++ii)
  {
    pos.x += ii * 10;
    spawn(std::make_shared<Coin>(), pos);
  }
}
