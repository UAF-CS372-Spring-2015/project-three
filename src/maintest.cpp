// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// test.cpp

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
//#include <SFML/Graphics.hpp>
#include "Player.h"
//#include <memory>
//using std::shared_ptr;

TEST_CASE("Implement The Platformer", "Platformer")
{
	REQUIRE(0==0);
	Player testPlayer;
	REQUIRE(testPlayer.getLives() == 3);

	sf::FloatRect boundingBox = testPlayer.getBoundingBox();

	//REQUIRE(boundingBox.left == 16);
	//REQUIRE(boundingBox.top == 16);
	//REQUIRE(boundingBox.width == 16);
	REQUIRE(boundingBox.height == 16);
}
