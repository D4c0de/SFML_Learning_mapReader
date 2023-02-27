#include <fstream>
#include <iostream>
#include "GameWorld.h"

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS_GLOBALS

int main() {
	
    GameWorld world(2);
	sf::Window* window = world.window;
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
		}
		world.drawInRenege();

	}
}