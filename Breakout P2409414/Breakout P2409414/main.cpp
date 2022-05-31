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
	sf::RenderWindow window(sf::VideoMode(800, 600), "Breakout Game P2409414", sf::Style::Titlebar | sf::Style::Close); ///< Creating the window to draw the game to using sf::RenderWindow.
	window.setFramerateLimit(60); ///< Sets the framerate of the window to 60 to allow for a smoother game.
	sf::Event ev; ///< Creates the event used to check for any input.
	Game game; ///< Creates the game using the Game class

	clock_t t; ///< Creates the clock.
	t = clock(); ///< Stores the clock time.
	game.setBlocksTrue(); ///< Calls the setBlocksTrue function from the game class to draw all the blocks.

	while (window.isOpen()) ///< While loop to run code if the window is open.
	{
		window.clear(sf::Color::White); ///< Clear the window to allow for drawing.

		while (window.pollEvent(ev)) ///< While the window is open check for input.
		{
			switch (ev.type) ///< Switch to check for an event.
			{
			case sf::Event::Closed: ///< Case to see if the close button is clicked.
				window.close(); ///< Closes the window.
				break;
			case sf::Event::KeyPressed: ///< Case to see if a key is pressed.
				if (ev.key.code == sf::Keyboard::Escape) ///< If statement to see if escape is pressed to run code.
					window.close(); ///< Closes the window.
				break;
			default:
				game.processEvent(ev); ///< Always pass the event to the game class to check it there too.
				break;
			}
		}

		float fElapsedTime = difftime(clock(), t); ///< Stores the difference between the current clock and the stored time since the lass storing.

		if (fElapsedTime > 0.01) ///< Makes sure the elapsed time is long enough.
		{
			game.update(fElapsedTime); ///< Hands the elapsed time the program has run for to the Game class.
			t = clock(); ///< Stores the current time for the next update.
		}

		window.draw(game); ///< Draws anything given to the function from the Game class.

		window.display(); ///< Display the window.

		if (game.win() == true) { ///< If statement to check the Game class' winState value is true.
			window.close(); ///< Closes the window.
			cout << "All blocks have been destroyed, you win!"; ///< Prints a win message to the console.
		}
		if (game.lose() == true) { ///< If statement to check the Game class' loseState value is true.
			window.close(); ///< Closes the window.
			cout << "The ball has fallen below the paddle, you lose!"; ///< Prints a lose message to the console.
		}
	}
	return 0;
}