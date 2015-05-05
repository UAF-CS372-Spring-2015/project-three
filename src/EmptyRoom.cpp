// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// EmptyRoom.cpp

#include "EmptyRoom.h"

EmptyRoom::EmptyRoom(): Room()
{
}

void EmptyRoom::generateContent()
{
  initializeShape();
}
