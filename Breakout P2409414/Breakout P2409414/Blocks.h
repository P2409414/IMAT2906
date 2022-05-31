#pragma once

#include<iostream>
#include<vector>
#include "Paddle.h"

///
/// Creates the Blocks class deriving from sf::RectangleShape
///

class Blocks : public sf::RectangleShape
{
public:
	Blocks(); ///< Constructor.
	Blocks(sf::Vector2f position, sf::Vector2f dimensions, sf::Color color, sf::Color color2); ///< Function to pass data from the Game class.
	bool checkCollisions(PhysicsObject& other) const; ///< Function to allow collision checks to be done from this class.
};