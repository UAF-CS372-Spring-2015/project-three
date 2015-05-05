#include "RandomWall.h"
#include "RoomWall.h"
#include <memory>

void RandomWalls::generateContent(Room * room)
{
  auto topWall = std::make_shared<RoomWall>(250, 50);
  room->spawn(topWall, room->getRandomPosition());

  // room->spawn(wall, );
}
