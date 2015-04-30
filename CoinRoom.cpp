#include "CoinRoom.h"
#include "Coin.h"
#include <memory>
using std::make_shared;

CoinRoom::CoinRoom(): Room()
{
}

void CoinRoom::generateContent()
{
  auto pos = getCenter();

  for(auto ii=0; ii < 10; ++ii)
  {
    pos.x += ii * 10;
    spawn(make_shared<Coin>(), pos);
  }
}
