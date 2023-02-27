#pragma once
#include "GameTile.h"
#include <vector>
class GameWorld
{
public:
	GameWorld(int,const int,sf::RenderWindow*);
	~GameWorld();
	int viewDistance;
	float scale;
	int textureSize;
	sf::RenderWindow* window;
	std::vector<GameTile*> tiles;
	sf::Vector2i center;
	void readFromMap();
	void drawInRenege();
	float setScale();
	void checkPressedKey();


private:

};