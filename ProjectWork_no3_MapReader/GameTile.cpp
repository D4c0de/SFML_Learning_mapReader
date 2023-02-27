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

void GameTile::setSpritePos(int x,int y)
{
	
	sprite.setPosition((pos.x-x) * 50, (pos.y-y) * 50);
}

void GameTile::setUpSprite()
{
	
	
	std::string string;
	switch (id)
	{
	case(101):
		string = "grass.png";
		break;
	default:
		string = "error.png";
		break;
	}
	texture.loadFromFile(string);
	sprite.setTexture(texture);
}

GameTile::~GameTile()
{
}