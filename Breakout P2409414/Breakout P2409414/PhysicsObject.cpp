#include "PhysicsObject.h"
#include "paddle.h"

PhysicsObject::PhysicsObject()
{
}

///
/// PhysicsObject function used to create and store data for a physics object.
///

PhysicsObject::PhysicsObject(sf::Vector2f position, sf::Vector2f dimensions, sf::Vector2f velocity, sf::Color color)
{
	setPosition(position); ///< Sets position of the physics object to the data passed through the calling of the function.
	setSize(dimensions); ///< Sets size of the physics object to the data passed through the calling of the function.
	setOrigin(dimensions.x / 2.f, dimensions.y / 2.f); ///< Sets origin of the physics object to the data passed through the calling of the function.
	setFillColor(color); ///< Sets fill colour of the physics object to the data passed through the calling of the function.
	physVelocity = velocity; ///< Sets velocity of the physics object to the data passed through the calling of the function.
}

///
/// PhysicsObject update function to get the object moving (created for the ball object).
///

void PhysicsObject::update(float time)
{
	sf::Vector2f newPosition = getPosition() + (physVelocity * time); ///< Stores the next position for the ball to be in using the current position + (the velocity of the ball * by the time passed)
	setPosition(newPosition); ///< Sets the position of the ball to the stored next position.
}

///
/// PhysicsObject getVelocity function in order to send the value to the location called at.
///

sf::Vector2f PhysicsObject::getVelocity()
{
	return physVelocity; ///< Returns the velocity.
}

///
/// PhysicsObject SetVelocity function to be passed a value from outside the class.
///

void PhysicsObject::setVelocity(sf::Vector2f velocity)
{
	physVelocity = velocity; ///< Sets the velocity to the given value.
}
