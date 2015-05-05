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
  initializeShape();
  
  auto roomSize = getSize();
  std::shared_ptr<Coin> coin;

  for(auto ii=0; ii < 10; ++ii)
  {
    auto pos = getRandomPosition();
    if (pos.x < 100)
      pos.x = 100;
    if (pos.x > roomSize.x - 100)
      pos.x = roomSize.x - 100;
    if (pos.y < 100)
      pos.y = 100;
    if (pos.y > roomSize.y - 100)
      pos.y = roomSize.y - 100;

    coin = std::make_shared<Coin>();
    spawn(coin, pos);
  }
}
