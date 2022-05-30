#pragma once

#include "PhysicsObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Paddle : public PhysicsObject
{
public:
	Paddle();
	Paddle(sf::Vector2f position, sf::Vector2f dimensions, sf::Color color);
	void processEvent(sf::Event& e);
	bool checkCollisions(PhysicsObject& other) const;
	void setVelocity(sf::Vector2f& velocity);
};

