#ifndef __THEPLATFORMER_COIN_ROOM_H__
#define __THEPLATFORMER_COIN_ROOM_H__

#include "Room.h"

class CoinRoom : public Room
{
public:
  CoinRoom();
  virtual void generateContent() override;
};

#endif
