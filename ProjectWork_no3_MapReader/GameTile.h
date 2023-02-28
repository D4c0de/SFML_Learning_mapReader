#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class GameTile
{
public:
	GameTile();
	GameTile(int, int, int);
	GameTile(int, int, int, const sf::Texture&);
	~GameTile();
	sf::Vector2i pos;
	sf::Sprite sprite;
	sf::Texture texture;
	int id;
	void setSpritePos(int,int);
	sf::Sprite getSprite();
	sf::Sprite getSprite(float);

private:
	void setUpSprite(bool);
	void setUpSprite();
};


class Center: public GameTile
{
public:
	Center(int, int);
	~Center();

private:

};