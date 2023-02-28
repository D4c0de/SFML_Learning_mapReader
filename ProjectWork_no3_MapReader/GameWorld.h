#pragma once
#include "GameTile.h"
#include <vector>
class GameWorld
{
public:
	GameWorld(int,const int,sf::RenderWindow*);
	~GameWorld();
	
	bool isToolBarChosed=false;
	int viewDistance;
	float scale;
	int textureSize;
	sf::RenderWindow* window;
	std::vector<GameTile*> tiles;
	sf::Texture* curentPlacing;
	Center* center;
	void readFromMap();
	void drawInRenege();
	float setScale();
	void checkPressedKey();
	void drawAbleSprite();
	void dr(const std::string&);
	std::vector<sf::Texture> textures;

private:

};