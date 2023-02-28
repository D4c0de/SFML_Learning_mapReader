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
GameTile::GameTile(int x, int y, int _id,const sf::Texture& _texture)
{
	pos.x = x;
	pos.y = y;
	id = _id;
	texture = _texture;
	setUpSprite(true);
}

void GameTile::setSpritePos(int x,int y)
{
	
	sprite.setPosition((pos.x-x) * 50, (pos.y-y) * 50);
}

sf::Sprite GameTile::getSprite()
{

	return this->sprite;
}

sf::Sprite GameTile::getSprite(float scale)
{
	sf::Sprite sprite = this->sprite;
	sf::Vector2f pos = sprite.getPosition();
	pos *= scale;
	sprite.setPosition(pos);
	sprite.setScale(scale, scale);
	return sprite;
}
void GameTile::setUpSprite() {
	setUpSprite(false);
}
void GameTile::setUpSprite(bool istexTextureAttached)
{
	
	if (!istexTextureAttached)
	{
		std::string string;
		switch (id)
		{
		case(100):
			string = "grass.png";
			break;
		default:
			string = "error.png";
			break;
		}
		texture.loadFromFile(string);
	}
	sprite.setTexture(texture);
}

GameTile::~GameTile()
{
}

Center::Center(int x,int y)
{

	pos.x = x;
	pos.y = y;
	id = -1;
	texture.loadFromFile("center.png");
	sprite.setTexture(texture);

}

Center::~Center()
{
}
