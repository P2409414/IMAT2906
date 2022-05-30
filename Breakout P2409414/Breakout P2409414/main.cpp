#include <iostream>
#include "Game.h"
#include "Borders.h"
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Breakout Game P2409414", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);
	sf::Event ev;
	Game game;

	clock_t t;
	t = clock();
	game.setBlocksTrue();

	while (window.isOpen())
	{
		window.clear(sf::Color::White);

		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			default:
				game.processEvent(ev);
				break;
			}
		}

		float fElapsedTime = difftime(clock(), t);

		if (fElapsedTime > 0.01)
		{
			game.update(fElapsedTime);
			t = clock();
		}

		window.draw(game);

		window.display();

		if (game.win() == true) { 
			window.close();
			cout << "All blocks have been destroyed, you win!";
		}
		if (game.lose() == true) { 
			window.close(); 
			cout << "The ball has fallen below the paddle, you lose!";
		}
	}
	return 0;
}