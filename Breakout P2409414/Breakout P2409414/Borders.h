#pragma once

#include<iostream>
#include<vector>
#include "Paddle.h"

class Borders : public sf::RectangleShape
{
public:
	Borders();
	Borders(sf::Vector2f position, sf::Vector2f dimensions, sf::Color color);
	bool checkCollisions(Paddle& other) const;
	bool checkCollisions(PhysicsObject& other) const;
};