// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// CoinRoom.cpp

#include "CoinRoom.h"
#include "Coin.h"
#include "RoomWall.h"
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
    auto coinPosition = getRandomPosition();
    if (coinPosition.x < 100)
      coinPosition.x = 100;
    if (coinPosition.x > roomSize.x - 100)
      coinPosition.x = roomSize.x - 100;
    if (coinPosition.y < 100)
      coinPosition.y = 100;
    if (coinPosition.y > roomSize.y - 100)
      coinPosition.y = roomSize.y - 100;

    coin = std::make_shared<Coin>();
    spawn(coin, coinPosition);
  }
}
