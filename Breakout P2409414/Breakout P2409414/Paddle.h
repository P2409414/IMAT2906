#pragma once

#include "PhysicsObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

///
/// Creates the PhysicsObject class deriving from the PhysicsObject class.
///

class Paddle : public PhysicsObject
{
public:
	Paddle(); ///< Constructor.
	Paddle(sf::Vector2f position, sf::Vector2f dimensions, sf::Color color); ///< Function to pass data from the Game class.
	void processEvent(sf::Event& e); ///< Function to allow keypresses to be used in this class.
	bool checkCollisions(PhysicsObject& other) const; ///< Function to allow collision checks to be done from this class.
};

