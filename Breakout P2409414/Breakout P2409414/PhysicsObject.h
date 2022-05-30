#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Paddle;

class PhysicsObject : public sf::RectangleShape
{
protected:
	sf::Vector2f physVelocity;
public:
	PhysicsObject();
	PhysicsObject(sf::Vector2f position, sf::Vector2f dimensions, sf::Vector2f velocity, sf::Color color);
	void update(float time);
	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f velocity);
};

