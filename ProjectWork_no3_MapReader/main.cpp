#include <fstream>
#include <iostream>
#include "GameWorld.h"
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS_GLOBALS

int main() {
	
	const int windowHeight = 800;
	const int windowWidth = 800;
	const int textureSize=50;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "game");
    GameWorld world(9,textureSize,&window);
	world.drawInRenege();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		world.checkPressedKey();
		world.drawInRenege();
		Sleep(200);

	}
}