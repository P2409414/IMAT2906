#include "Paddle.h"
using namespace std;

Paddle::Paddle()
{
}

Paddle::Paddle(sf::Vector2f position, sf::Vector2f dimensions, sf::Color color)
{
	physVelocity = sf::Vector2f(0.f, 0.f);
	setPosition(position);
	setSize(dimensions);
	setOrigin(dimensions.x / 2.f, dimensions.y / 2.f);
	setFillColor(color);
}

void Paddle::processEvent(sf::Event& e)
{
	if (sf::Event::KeyPressed)
	{
		if (e.key.code == sf::Keyboard::Left)
		{
			move(sf::Vector2f((-getSize().x / 2), 0.1));
		}
		else if (e.key.code == sf::Keyboard::Right)
		{
			move(sf::Vector2f((getSize().x / 2), 0.1));
		}
	}
}

bool Paddle::checkCollisions(PhysicsObject& other) const
{
	return getGlobalBounds().intersects(other.getGlobalBounds());
}

void Paddle::setVelocity(sf::Vector2f & velocity)
{
	physVelocity = velocity;
}
