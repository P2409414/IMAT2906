#pragma once

#include<iostream>
#include<vector>
#include "Paddle.h"

class Blocks : public sf::RectangleShape
{
public:
	Blocks();
	Blocks(sf::Vector2f position, sf::Vector2f dimensions, sf::Color color, sf::Color color2);
	bool checkCollisions(PhysicsObject& other) const;
};