#include "Paddle.h"
using namespace std;

Paddle::Paddle()
{
}

///
/// Paddle function used to create and store data for the paddle object.
///

Paddle::Paddle(sf::Vector2f position, sf::Vector2f dimensions, sf::Color color)
{
	physVelocity = sf::Vector2f(0.f, 0.f); ///< Sets velocity of the paddle to 0 so that it does not move in each frame unless a key is pressed to move it.
	setPosition(position); ///< Sets position of the paddle to the data passed through the calling of the function.
	setSize(dimensions); ///< Sets size of the paddle to the data passed through the calling of the function.
	setOrigin(dimensions.x / 2.f, dimensions.y / 2.f); ///< Sets origin of the paddle to the data passed through the calling of the function.
	setFillColor(color); ///< Sets fill colour of the paddle to the data passed through the calling of the function.
}

///
/// Paddle processEvent function to check for keys pressed to move the paddle.
///

void Paddle::processEvent(sf::Event& e)
{
	if (sf::Event::KeyPressed) ///< If statement to check if the event is a key press.
	{
		if (e.key.code == sf::Keyboard::Left) ///< Check if the key press is the left arrow.
		{
			move(sf::Vector2f((-getSize().x / 2), 0.1)); ///< Move the paddle to the left by a portion of the size of the paddle.
		}
		else if (e.key.code == sf::Keyboard::Right) ///< Check if the key press if the right arrow.
		{
			move(sf::Vector2f((getSize().x / 2), 0.1)); ///< Move the paddle to the right by a portion of the size of the paddle.
		}
	}
}

///
/// Paddle checkCollisions function to check the global bounds intersections with other physics objects.
///

bool Paddle::checkCollisions(PhysicsObject& other) const
{
	return getGlobalBounds().intersects(other.getGlobalBounds()); ///< Gets any intersects between the paddle's global bounds and the physics object's global bounds.
}
