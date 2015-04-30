#ifndef __THEPLATFORMER_EMPTY_ROOM_H__
#define __THEPLATFORMER_EMPTY_ROOM_H__

#include "Room.h"

class EmptyRoom : public Room
{
public:
  EmptyRoom();
  virtual void generateContent() override;
};

#endif
