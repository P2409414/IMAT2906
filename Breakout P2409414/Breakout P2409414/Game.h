#pragma once

#include <array>
#include "Paddle.h"
#include "Borders.h"
#include "Blocks.h"
#include "PhysicsObject.h"
using namespace std;

///
/// Creates the Game class deriving from sf::Drawable
///

class Game : public sf::Drawable
{
private:
	Paddle userPaddle; ///< Create paddle.
	PhysicsObject ball; ///< Create ball.
	array<Borders, 4> borders; ///< Create borders array.
	array<Blocks, 5> blocks; ///< Create blocks array.
	sf::Vector2f ballStart; ///< Create ballStart variable.
	sf::Vector2f ballVelocity; ///< Create ballVelocity variable.
	bool block0; ///< Create first block bool.
	bool block1; ///< Create second block bool.
	bool block2; ///< Create third block bool.
	bool block3; ///< Create fourth block bool.
	bool block4; ///< Create fifth block bool.
	bool winState = false; ///< winState bool set to false.
	bool loseState = false; ///< loseState bool set to false.
	bool paused = false; ///< paused bool set to false.
public:
	Game(); ///< Constructor.
	void update(float time); ///< Function to allow updates to be handled from within this class.
	void draw(sf::RenderTarget& target, sf::RenderStates states) const; ///< Function to allow objects from the game class to be drawn to the RenderWindow in main.cpp.
	void processEvent(sf::Event& e); ///< Function to allow events to be processed within this class.
	void setBlocksTrue(); ///< Function to set all the blocks to draw.
	bool win(); ///< Function to send the bool value of the winState variable to main.cpp.
	bool lose(); ///< Function to send the bool value of the loseState variable to main.cpp.
};

