#include "PhysicsObject.h"
#include "paddle.h"

PhysicsObject::PhysicsObject()
{
}

PhysicsObject::PhysicsObject(sf::Vector2f position, sf::Vector2f dimensions, sf::Vector2f velocity, sf::Color color)
{
	setPosition(position);
	setSize(dimensions);
	setOrigin(dimensions.x / 2.f, dimensions.y / 2.f);
	setFillColor(color);
	physVelocity = velocity;
}

void PhysicsObject::update(float time)
{
	sf::Vector2f newPosition = getPosition() + (physVelocity * time);
	setPosition(newPosition);
}

sf::Vector2f PhysicsObject::getVelocity()
{
	return physVelocity;
}

void PhysicsObject::setVelocity(sf::Vector2f velocity)
{
	physVelocity = velocity;
}
