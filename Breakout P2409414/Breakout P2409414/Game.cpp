#include "Game.h"

///
/// Game constructor that puts data into all the variables on program start.
///

Game::Game()
{
	ballStart = sf::Vector2f(400.f, 300.f); ///< Putting data into the ballstart location.
	ball = PhysicsObject(ballStart, sf::Vector2f(40.f, 40.f), sf::Vector2f(0.25, -0.25), sf::Color(60, 205, 60)); ///< Inputting the data required to create the ball object using the PhysicsObject class.
	userPaddle = Paddle(sf::Vector2f(400.f, 600.f), sf::Vector2f(150.f, 40.f), sf::Color(255, 50, 50)); ///< Inputting the data required to create the paddle using the Paddle class.
	borders.at(0) = Borders(sf::Vector2f(400.f, 20.f), sf::Vector2f(800.f, 40.f), sf::Color(60, 60, 205)); ///< Inputting the data for the first border using the Borders class.
	borders.at(1) = Borders(sf::Vector2f(20.f, 300.f), sf::Vector2f(40.f, 600.f), sf::Color(60, 60, 205));  ///< Inputting the data for the second border using the Borders class.
	borders.at(2) = Borders(sf::Vector2f(780.f, 300.f), sf::Vector2f(40.f, 600.f), sf::Color(60, 60, 205));  ///< Inputting the data for the third border using the Borders class.
	borders.at(3) = Borders(sf::Vector2f(20.f, 700.f), sf::Vector2f(1600.f, 40.f), sf::Color(60, 60, 205));  ///< Inputting the data for the fourth border using the Borders class.

	blocks.at(0) = Blocks(sf::Vector2f(100.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Green, sf::Color::Color(100, 200, 100)); ///< Inputting the data for the first block using the Blocks class.
	blocks.at(1) = Blocks(sf::Vector2f(250.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Green, sf::Color::Color(100, 200, 100)); ///< Inputting the data for the second block using the Blocks class.
	blocks.at(2) = Blocks(sf::Vector2f(400.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Green, sf::Color::Color(100, 200, 100)); ///< Inputting the data for the third block using the Blocks class.
	blocks.at(3) = Blocks(sf::Vector2f(550.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Green, sf::Color::Color(100, 200, 100)); ///< Inputting the data for the fourth block using the Blocks class.
	blocks.at(4) = Blocks(sf::Vector2f(700.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Green, sf::Color::Color(100, 200, 100)); ///< Inputting the data for the fifth block using the Blocks class.
}

///
/// Game update function to be done every frame to allow collision checks to be made so that I can make the ball bounce off of the paddle and the borders and destroy blocks. Also used for win/lose state checks and pause checks.
///

void Game::update(float time)
{
	ball.update(time); ///< Calls the update function from the PhysicsObject class to allow the ball to move.
	if (borders.at(1).checkCollisions(userPaddle)) { userPaddle.setPosition(sf::Vector2f(115.f, userPaddle.getPosition().y)); } ///< If statement that checks for paddle collision with the border and stops the paddle from passing through.
	if (borders.at(2).checkCollisions(userPaddle)) { userPaddle.setPosition(sf::Vector2f(685.f, userPaddle.getPosition().y)); } ///< If statement that checks for paddle collision with the border and stops the paddle from passing through.
	if (userPaddle.checkCollisions(ball))  { ///< If statement  that checks for the collision between the paddle and ball and gets the Y postion of the ball to ensure it bounces correctly off of the paddle.
		if (ball.getPosition().y < 601.f) {
			ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y)); ///< Sets the velocity of the ball to the same X velocity but the opposite Y velocity to bounce it in the Y direction.
		} else {
			ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y)); ///< Sets the velocity of the ball to the same Y velocity but the opposite X velocity to bounce it in the X direction.
		}
	}
	if (blocks.at(0).checkCollisions(ball)) { ///< If statement that checks for the collision between the first block and the ball and gets the Y position of the ball to ensure it bounces correctly off of the block as well as change the colour in the first stage and destroy it in the second stage.
		if (blocks.at(0).getFillColor() == sf::Color::Green) {
			if (ball.getPosition().y > 139.f) {
				ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y)); ///< Sets the velocity of the ball to the same X velocity but the opposite Y velocity to bounce it in the Y direction.
				blocks.at(0) = Blocks(sf::Vector2f(100.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0)); ///< Changes the colour of the block while keeping everything else the same.
			} else {
				ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y)); ///< Sets the velocity of the ball to the same Y velocity but the opposite X velocity to bounce it in the X direction.
				blocks.at(0) = Blocks(sf::Vector2f(100.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0)); ///< Changes the colour of the block while keeping everything else the same.
			}
		} else {
			block0 = false; ///< Sets the first block to false to unload it.
		}
	}
	if (blocks.at(1).checkCollisions(ball)) { ///< If statement that checks for the collision between the second block and the ball and gets the Y position of the ball to ensure it bounces correctly off of the block as well as change the colour in the first stage and destroy it in the second stage.
		if (blocks.at(1).getFillColor() == sf::Color::Green) {
			if (ball.getPosition().y > 139.f) {
				ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y)); ///< Sets the velocity of the ball to the same X velocity but the opposite Y velocity to bounce it in the Y direction.
				blocks.at(1) = Blocks(sf::Vector2f(250.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0)); ///< Changes the colour of the block while keeping everything else the same.
			} else {
				ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y)); ///< Sets the velocity of the ball to the same Y velocity but the opposite X velocity to bounce it in the X direction.
				blocks.at(1) = Blocks(sf::Vector2f(250.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0)); ///< Changes the colour of the block while keeping everything else the same.
			}
		} else {
			block1 = false; ///< Sets the first block to false to unload it.
		}
	}
	if (blocks.at(2).checkCollisions(ball)) { ///< If statement that checks for the collision between the third block and the ball and gets the Y position of the ball to ensure it bounces correctly off of the block as well as change the colour in the first stage and destroy it in the second stage.
		if (blocks.at(2).getFillColor() == sf::Color::Green) {
			if (ball.getPosition().y > 139.f) {
				ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y)); ///< Sets the velocity of the ball to the same X velocity but the opposite Y velocity to bounce it in the Y direction.
				blocks.at(2) = Blocks(sf::Vector2f(400.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0)); ///< Changes the colour of the block while keeping everything else the same.
			} else {
				ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y)); ///< Sets the velocity of the ball to the same Y velocity but the opposite X velocity to bounce it in the X direction.
				blocks.at(2) = Blocks(sf::Vector2f(400.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0)); ///< Changes the colour of the block while keeping everything else the same.
			}
		} else {
			block2 = false; ///< Sets the first block to false to unload it.
		}
	}
	if (blocks.at(3).checkCollisions(ball)) { ///< If statement that checks for the collision between the fourth block and the ball and gets the Y position of the ball to ensure it bounces correctly off of the block as well as change the colour in the first stage and destroy it in the second stage.
		if (blocks.at(3).getFillColor() == sf::Color::Green) {
			if (ball.getPosition().y > 139.f) {
				ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y)); ///< Sets the velocity of the ball to the same X velocity but the opposite Y velocity to bounce it in the Y direction.
				blocks.at(3) = Blocks(sf::Vector2f(550.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0)); ///< Changes the colour of the block while keeping everything else the same.
			}
			else {
				ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y)); ///< Sets the velocity of the ball to the same Y velocity but the opposite X velocity to bounce it in the X direction.
				blocks.at(3) = Blocks(sf::Vector2f(550.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0)); ///< Changes the colour of the block while keeping everything else the same.
			}
		}
		else {
			block3 = false; ///< Sets the first block to false to unload it.
		}
	}
	if (blocks.at(4).checkCollisions(ball)) { ///< If statement that checks for the collision between the fifth block and the ball and gets the Y position of the ball to ensure it bounces correctly off of the block as well as change the colour in the first stage and destroy it in the second stage.
		if (blocks.at(4).getFillColor() == sf::Color::Green) {
			if (ball.getPosition().y > 139.f) {
				ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y)); ///< Sets the velocity of the ball to the same X velocity but the opposite Y velocity to bounce it in the Y direction.
				blocks.at(4) = Blocks(sf::Vector2f(700.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0)); ///< Changes the colour of the block while keeping everything else the same.
			}
			else {
				ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y)); ///< Sets the velocity of the ball to the same Y velocity but the opposite X velocity to bounce it in the X direction.
				blocks.at(4) = Blocks(sf::Vector2f(700.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0)); ///< Changes the colour of the block while keeping everything else the same.
			}
		}
		else {
			block4 = false; ///< Sets the first block to false to unload it.
		}
	}
	if (borders.at(0).checkCollisions(ball)) { ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y)); } ///< If statement that checks for the collision between the first border and the ball and bounces the ball off the border.
	if (borders.at(1).checkCollisions(ball)) { ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y)); } ///< If statement that checks for the collision between the second border and the ball and bounces the ball off the border.
	if (borders.at(2).checkCollisions(ball)) { ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y)); } ///< If statement that checks for the collision between the third border and the ball and bounces the ball off the border.
	if (borders.at(3).checkCollisions(ball)) { loseState = true; } ///< If statement that checks for the collision between the fourth border and the ball and sets the lose state to true in order to end the game due the ball dropping off of the screen past the paddle.
	if (block0 == false && block1 == false && block2 == false && block3 == false && block4 == false) {  ///< If statement that checks for all five blocks being destroyed and sets the win state to true to end the game.
		winState = true; ///< Sets winstate to true to end the game.
	}
}

///
/// Game draw function to pass data to the RenderWindow in main.cpp
///

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < borders.size(); i++) { target.draw(borders.at(i)); } ///< for loop to draw all of the borders.
	if (block0) { ///< If statement to check for the first block being destroyed or not.
		target.draw(blocks.at(0)); ///< Draws the first block.
	}
	if (block1) { ///< If statement to check for the second block being destroyed or not and then draw the block.
		target.draw(blocks.at(1)); ///< Draws the second block.
	}
	if (block2) { ///< If statement to check for the third block being destroyed or not and then draw the block.
		target.draw(blocks.at(2)); ///< Draws the third block.
	}
	if (block3) { ///< If statement to check for the fourth block being destroyed or not and then draw the block.
		target.draw(blocks.at(3)); ///< Draws the fourth block.
	}
	if (block4) { ///< If statement to check for the fifth block being destroyed or not and then draw the block.
		target.draw(blocks.at(4)); ///< Draws the fifth block.
	}
	target.draw(userPaddle); ///< Draw the userpaddle.
	target.draw(ball); ///< Draw the ball.
}

///
/// Game processEvent function to process any events from the RenderWindow in main to allow for the movement of the paddle controlled by the keyboard and the pause function.
///

void Game::processEvent(sf::Event& e)
{
	userPaddle.processEvent(e); ///< Hands data over to the Paddle function for processing keypresses.
	if (sf::Event::KeyPressed) ///< If statement to check for the "P" button being pressed and to then either pause or unpause the ball's movement.
	{
		if (e.key.code == sf::Keyboard::P)
		{
			if (paused == false)
			{
				ballVelocity = ball.getVelocity(); ///< Stores the current ball velocity.
				ball.setVelocity(sf::Vector2f(0.f, 0.f)); ///< Sets the ball velocity to 0.
				paused = true; ///< sets the paused variable to true so that it will unpause the next time "P" is pressed.
			}
			else {
				ball.setVelocity(ballVelocity); ///< Sets the ball velocity to the stored velocity.
				paused = false; ///< sets the paused variable to false so that it will pause the next time "P" is pressed.
			}
		}
	}
}

///
/// Game setBlocksTrue function that is called in main to draw the blocks once the game has loaded.
///

void Game::setBlocksTrue()
{
	block0 = true; ///< Sets the first block to true.
	block1 = true; ///< Sets the second block to true.
	block2 = true; ///< Sets the third block to true.
	block3 = true; ///< Sets the fourth block to true.
	block4 = true; ///< Sets the fifth block to true.
}

///
/// Game win function to check for the winState bool and either end the game or continue it depending on the value.
///

bool Game::win()
{
	if (winState == false) { ///< If statement to check to see if the game is still going.
		return false; ///< Returns false if the game is still going.
	} else {
		return true; ///< Returns true if all blocks have been destroyed.
	}
}

///
/// Game win function to check for the loseState bool and either end the game or continue it depending on the value.
///

bool Game::lose()
{
	if (loseState == false) { ///< If statement to check to see if the game is still going.
		return false; ///< Returns false if the game is still going.
	}
	else {
		return true; ///< Returns true if the ball has fallen past the paddle.
	}
}
