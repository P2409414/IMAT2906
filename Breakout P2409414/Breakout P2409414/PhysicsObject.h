#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Paddle;

///
/// Creates the PhysicsObject class deriving from sf::RectangleShape
///

class PhysicsObject : public sf::RectangleShape
{
protected:
	sf::Vector2f physVelocity;
public:
	PhysicsObject(); ///< Constructor.
	PhysicsObject(sf::Vector2f position, sf::Vector2f dimensions, sf::Vector2f velocity, sf::Color color); ///< Function to pass data from the Game class.
	void update(float time); ///< Function to allow updates to physics objects to be handled from within this class.
	sf::Vector2f getVelocity(); ///< Function to send the velocity of the physics object to the Game class.
	void setVelocity(sf::Vector2f velocity); ///< Function to allow data to be sent from the Game class to this class in order to set the physics object's velocity.
};

