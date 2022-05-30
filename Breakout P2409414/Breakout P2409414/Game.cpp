#include "Game.h"

Game::Game()
{
	ballStart = sf::Vector2f(400.f, 300.f);
	ball = PhysicsObject(ballStart, sf::Vector2f(40.f, 40.f), sf::Vector2f(0.25, -0.25), sf::Color(60, 205, 60));
	userPaddle = Paddle(sf::Vector2f(400.f, 600.f), sf::Vector2f(150.f, 40.f), sf::Color(255, 50, 50));
	borders.at(0) = Borders(sf::Vector2f(400.f, 20.f), sf::Vector2f(800.f, 40.f), sf::Color(60, 60, 205));
	borders.at(1) = Borders(sf::Vector2f(20.f, 300.f), sf::Vector2f(40.f, 600.f), sf::Color(60, 60, 205));
	borders.at(2) = Borders(sf::Vector2f(780.f, 300.f), sf::Vector2f(40.f, 600.f), sf::Color(60, 60, 205));
	borders.at(3) = Borders(sf::Vector2f(20.f, 700.f), sf::Vector2f(1600.f, 40.f), sf::Color(60, 60, 205));

	blocks.at(0) = Blocks(sf::Vector2f(100.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Green, sf::Color::Color(100, 200, 100));
	blocks.at(1) = Blocks(sf::Vector2f(250.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Green, sf::Color::Color(100, 200, 100));
	blocks.at(2) = Blocks(sf::Vector2f(400.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Green, sf::Color::Color(100, 200, 100));
	blocks.at(3) = Blocks(sf::Vector2f(550.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Green, sf::Color::Color(100, 200, 100));
	blocks.at(4) = Blocks(sf::Vector2f(700.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Green, sf::Color::Color(100, 200, 100));
}

void Game::update(float time)
{
	ball.update(time);
	if (borders.at(1).checkCollisions(userPaddle)) { userPaddle.setPosition(sf::Vector2f(115.f, userPaddle.getPosition().y)); }
	if (borders.at(2).checkCollisions(userPaddle)) { userPaddle.setPosition(sf::Vector2f(685.f, userPaddle.getPosition().y)); }
	if (userPaddle.checkCollisions(ball))  {
		if (ball.getPosition().y < 601.f) {
			ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y));
		} else {
			ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y));
		}
	}
	if (blocks.at(0).checkCollisions(ball)) {
		if (blocks.at(0).getFillColor() == sf::Color::Green) {
			if (ball.getPosition().y > 139.f) {
				ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y));
				blocks.at(0) = Blocks(sf::Vector2f(100.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0));
			} else {
				ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y));
				blocks.at(0) = Blocks(sf::Vector2f(100.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0));
			}
		} else {
			block0 = false;
		}
	}
	if (blocks.at(1).checkCollisions(ball)) {
		if (blocks.at(1).getFillColor() == sf::Color::Green) {
			if (ball.getPosition().y > 139.f) {
				ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y));
				blocks.at(1) = Blocks(sf::Vector2f(250.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0));
			} else {
				ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y));
				blocks.at(1) = Blocks(sf::Vector2f(250.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0));
			}
		} else {
			block1 = false;
		}
	}
	if (blocks.at(2).checkCollisions(ball)) {
		if (blocks.at(2).getFillColor() == sf::Color::Green) {
			if (ball.getPosition().y > 139.f) {
				ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y));
				blocks.at(2) = Blocks(sf::Vector2f(400.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0));
			} else {
				ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y));
				blocks.at(2) = Blocks(sf::Vector2f(400.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0));
			}
		} else {
			block2 = false;
		}
	}
	if (blocks.at(3).checkCollisions(ball)) {
		if (blocks.at(3).getFillColor() == sf::Color::Green) {
			if (ball.getPosition().y > 139.f) {
				ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y));
				blocks.at(3) = Blocks(sf::Vector2f(550.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0));
			}
			else {
				ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y));
				blocks.at(3) = Blocks(sf::Vector2f(550.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0));
			}
		}
		else {
			block3 = false;
		}
	}
	if (blocks.at(4).checkCollisions(ball)) {
		if (blocks.at(4).getFillColor() == sf::Color::Green) {
			if (ball.getPosition().y > 139.f) {
				ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y));
				blocks.at(4) = Blocks(sf::Vector2f(700.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0));
			}
			else {
				ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y));
				blocks.at(4) = Blocks(sf::Vector2f(700.f, 100.f), sf::Vector2f(60.f, 40.f), sf::Color::Red, sf::Color::Color(255, 165, 0));
			}
		}
		else {
			block4 = false;
		}
	}
	if (borders.at(0).checkCollisions(ball)) { ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y)); }
	if (borders.at(1).checkCollisions(ball)) { ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y)); }
	if (borders.at(2).checkCollisions(ball)) { ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y)); }
	if (borders.at(3).checkCollisions(ball)) { loseState = true; }
	if (block0 == false && block1 == false && block2 == false && block3 == false && block4 == false) {
		winState = true;
	}
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < borders.size(); i++) { target.draw(borders.at(i)); }
	if (block0) {
		target.draw(blocks.at(0));
	}
	if (block1) {
		target.draw(blocks.at(1));
	}
	if (block2) {
		target.draw(blocks.at(2));
	}
	if (block3) {
		target.draw(blocks.at(3));
	}
	if (block4) {
		target.draw(blocks.at(4));
	}
	target.draw(userPaddle);
	target.draw(ball);
}

void Game::processEvent(sf::Event& e)
{
	userPaddle.processEvent(e);
	if (sf::Event::KeyPressed)
	{
		if (e.key.code == sf::Keyboard::P)
		{
			if (paused == false)
			{
				ballVelocity = ball.getVelocity();
				ball.setVelocity(sf::Vector2f(0.f, 0.f));
				paused = true;
			}
			else {
				ball.setVelocity(ballVelocity);
				paused = false;
			}
		}
	}
}

void Game::setBlocksTrue()
{
	block0 = true;
	block1 = true;
	block2 = true;
	block3 = true;
	block4 = true;
}

bool Game::win()
{
	if (winState == false) {
		return false;
	} else {
		return true;
	}
}

bool Game::lose()
{
	if (loseState == false) {
		return false;
	}
	else {
		return true;
	}
}
