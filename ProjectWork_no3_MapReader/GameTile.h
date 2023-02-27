#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class GameTile
{
public:
	GameTile();
	GameTile(int, int, int);
	~GameTile();
	sf::Vector2i pos;
	sf::Sprite sprite;
	sf::Texture texture;
	int id;
	void setSpritePos(int,int);
private:
	void setUpSprite();
};

