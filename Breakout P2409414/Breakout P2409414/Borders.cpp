#include "Borders.h"
Borders::Borders()
{
}

///
/// Borders function used to create and store data for a border object.
///

Borders::Borders(sf::Vector2f position, sf::Vector2f dimensions, sf::Color color)
{
	setPosition(position); ///< Sets position of the border to the data passed through the calling of the function.
	setSize(dimensions); ///< Sets size of the border to the data passed through the calling of the function.
	setOrigin(dimensions.x / 2.f, dimensions.y / 2.f); ///< Sets origin of the border to the data passed through the calling of the function.
	setFillColor(color); ///< Sets fill colour of the border to the data passed through the calling of the function.
}

///
/// Borders checkCollisions function used to check for global bounds intersects between Borders and the paddle.
///

bool Borders::checkCollisions(Paddle& other) const
{
	return getGlobalBounds().intersects(other.getGlobalBounds()); ///< Gets any intersects between the border's global bounds and the paddle's global bounds.
}

///
/// Borders checkCollisions function used to check for global bounds intersects between borders and physics objects.
///

bool Borders::checkCollisions(PhysicsObject& other) const
{
	return getGlobalBounds().intersects(other.getGlobalBounds()); ///< Gets any intersects between the border's global bounds and the physics object's global bounds.
}
