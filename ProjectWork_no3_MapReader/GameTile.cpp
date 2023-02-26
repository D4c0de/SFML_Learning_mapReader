#include "GameTile.h"

GameTile::GameTile()
{

}

GameTile::GameTile(int x, int y, int _id)
{
	pos.x = x;
	pos.y = y;
	id = _id;
	setUpSprite();
}

void GameTile::setUpSprite()
{
	
	sf::Texture texture;
	std::string string;
	switch (id)
	{
	case(100):
		string = "grass";
		break;
	default:
		string = "error";
		break;
	}
	texture.loadFromFile(string+".png");
	sprite.setTexture(texture);
	sprite.setPosition(pos.x, pos.y);
}

GameTile::~GameTile()
{
}