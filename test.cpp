// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// test.cpp

#define CATCH_CONFIG_MAIN
#include "Catch/single_include/catch.hpp"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <memory>
using std::shared_ptr;

TEST_CASE("Implement The Platformer", "Platformer")
{

	Player testPlayer;
    REQUIRE(testPlayer.getLives() == 3);

    
}