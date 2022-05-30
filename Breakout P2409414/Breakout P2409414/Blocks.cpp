#include "Blocks.h"
Blocks::Blocks()
{
}
Blocks::Blocks(sf::Vector2f position, sf::Vector2f dimensions, sf::Color color, sf::Color color2)
{
	setPosition(position);
	setSize(dimensions);
	setOrigin(dimensions.x / 2.f, dimensions.y / 2.f);
	setFillColor(color);
	setOutlineColor(color2);
	setOutlineThickness(5.f);
}

bool Blocks::checkCollisions(PhysicsObject& other) const
{
	return getGlobalBounds().intersects(other.getGlobalBounds());
}