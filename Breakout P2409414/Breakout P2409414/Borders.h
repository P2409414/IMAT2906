#pragma once

#include<iostream>
#include<vector>
#include "Paddle.h"

///
/// Creates the Borders class deriving from sf::RectangleShape
///

class Borders : public sf::RectangleShape
{
public:
	Borders(); ///< Constructor.
	Borders(sf::Vector2f position, sf::Vector2f dimensions, sf::Color color); ///< Function to pass data from the Game class.
	bool checkCollisions(Paddle& other) const; ///< Function to allow collision checks to be done from this class.
	bool checkCollisions(PhysicsObject& other) const; ///< Function to allow collision checks to be done from this class.
};