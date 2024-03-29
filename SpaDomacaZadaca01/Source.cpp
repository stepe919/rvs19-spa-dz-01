#include <SFML/Graphics.hpp>
#include "Pacman.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, PACMAN IS COMING!");
	window.setFramerateLimit(360);
	Pacman pacman(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		pacman.draw();
		window.display();
	}

	return 0;
}