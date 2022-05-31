#include "Blocks.h"
Blocks::Blocks()
{
}

///
/// Blocks function used to create and store data for a block object.
///

Blocks::Blocks(sf::Vector2f position, sf::Vector2f dimensions, sf::Color color, sf::Color color2)
{
	setPosition(position); ///< Sets position of the block to the data passed through the calling of the function.
	setSize(dimensions); ///< Sets size of the block to the data passed through the calling of the function.
	setOrigin(dimensions.x / 2.f, dimensions.y / 2.f); ///< Sets origin of the block to the data passed through the calling of the function.
	setFillColor(color); ///< Sets fill colour of the block to the data passed through the calling of the function.
	setOutlineColor(color2); ///< Sets outline colour of the block to the data passed through the calling of the function.
	setOutlineThickness(5.f);  ///< Sets outline thickness to 5.
}

///
/// Blocks checkCollisions function used to check for global bounds intersects between blocks and physics objects.
///

bool Blocks::checkCollisions(PhysicsObject& other) const
{
	return getGlobalBounds().intersects(other.getGlobalBounds()); ///< Gets any intersects between the block's global bounds and the physics object's global bounds.
}