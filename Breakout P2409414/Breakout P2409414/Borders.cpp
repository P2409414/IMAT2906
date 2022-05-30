#include "Borders.h"
Borders::Borders()
{
}
Borders::Borders(sf::Vector2f position, sf::Vector2f dimensions, sf::Color color)
{
	setPosition(position);
	setSize(dimensions);
	setOrigin(dimensions.x / 2.f, dimensions.y / 2.f);
	setFillColor(color);
}

bool Borders::checkCollisions(Paddle& other) const
{
	return getGlobalBounds().intersects(other.getGlobalBounds());
}

bool Borders::checkCollisions(PhysicsObject& other) const
{
	return getGlobalBounds().intersects(other.getGlobalBounds());
}
