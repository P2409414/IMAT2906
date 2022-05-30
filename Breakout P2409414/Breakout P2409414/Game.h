#pragma once

#include <array>
#include "Paddle.h"
#include "Borders.h"
#include "Blocks.h"
#include "PhysicsObject.h"
using namespace std;

class Game : public sf::Drawable
{
private:
	Paddle userPaddle;
	PhysicsObject ball;
	array<Borders, 4> borders;
	array<Blocks, 5> blocks;
	sf::Vector2f ballStart;
	sf::Vector2f ballVelocity;
	bool block0;
	bool block1;
	bool block2;
	bool block3;
	bool block4;
	bool winState = false;
	bool loseState = false;
	bool paused = false;
public:
	Game();
	void update(float time);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void processEvent(sf::Event& e);
	void setBlocksTrue();
	bool win();
	bool lose();
};

