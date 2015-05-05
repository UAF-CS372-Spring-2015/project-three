#include "RandomWall.h"
#include "RoomWall.h"
#include <memory>
#include <random>

void RandomWalls::generateContent(Room * room)
{
  std::random_device rd;
  std::uniform_int_distribution<int> randDirection(0, 100);
  std::shared_ptr<RoomWall> wall;

  if (randDirection(rd) < 50)
    wall = std::make_shared<RoomWall>(250, 50);
  else
    wall = std::make_shared<RoomWall>(50, 250);


  room->spawn(wall, room->getRandomPosition());
  // room->spawn(wall, );
}
