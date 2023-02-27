#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class GameTile
{
public:
	GameTile(int, int, int);
	~GameTile();
	sf::Vector2i pos;
	sf::Sprite sprite;
	sf::Texture texture;
	int id;
	void setSpritePos(int,int);
	sf::Sprite getSprite();
	sf::Sprite getSprite(float);

private:
	void setUpSprite();
};

