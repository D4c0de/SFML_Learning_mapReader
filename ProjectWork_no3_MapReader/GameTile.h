#pragma once
#include "SFML/Graphics.hpp"

class GameTile
{
public:
	GameTile();
	GameTile(int, int, int);
	~GameTile();
	sf::Vector2i pos;
	sf::Sprite sprite;
	int id;
private:
	void setUpSprite();
};

