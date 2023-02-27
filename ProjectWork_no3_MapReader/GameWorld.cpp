#include "GameWorld.h"
#include "bitmap_image.hpp"

GameWorld::GameWorld(int _viewDistance,const int _textureSize,sf::RenderWindow* _window)
{
    window = _window;
    textureSize = _textureSize;
    viewDistance = _viewDistance;
    readFromMap();
    scale =setScale();
}



void GameWorld::readFromMap() {
    
    bitmap_image map("map.bmp");
    unsigned int total_number_of_pixels = 0;

    const unsigned int height = map.height();
    const unsigned int width = map.width();

    for (std::size_t y = 0; y < height; ++y)
    {
        for (std::size_t x = 0; x < width; ++x)
        {
            rgb_t color;
            map.get_pixel(x, y, color);
            int red = color.red;
            int green = color.green;
            int blue = color.blue;
            int id = red;
            if (id==0)
            {

            }
            else if(id==255)
            {
                tiles.push_back(new GameTile(x, y, 100));
                center.x = x;
                center.y = y;
            }
            else
            {
                tiles.push_back(new GameTile(x, y, id));
            }
        }
    }
}

void GameWorld::drawInRenege()
{
    scale = setScale();
    window->clear();
    for (int i = 0; i < tiles.size(); i++)
    {

        int minX = center.x - (viewDistance/2);
        int maxX = center.x + (viewDistance/2);
        int minY = center.y - (viewDistance/2);
        int maxY = center.y + (viewDistance/2);
        int X = tiles[i]->pos.x;
        int Y = tiles[i]->pos.y;
        if (X >= minX && X <= maxX )
        {
            if (Y >= minY && Y <= maxY)
            {
                tiles[i]->setSpritePos(minX, minY);
                window->draw(tiles[i]->getSprite(scale));
            }
        }
    }
    window->display();

}

float GameWorld::setScale()
{

    sf::Vector2u windowSize = window->getSize();
    float textureSize = windowSize.x /viewDistance ;
    scale = textureSize / this->textureSize;
    return scale;
}

void GameWorld::checkPressedKey()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        center.x++;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        center.x--;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        center.y++;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        center.y--;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
    {
        if (viewDistance < 15)
        {
            viewDistance+=2;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
    {
        
        if (viewDistance > 5)
        {
            viewDistance-=2;
        }
    }
}

GameWorld::~GameWorld()
{
    for (int i = 0; i < tiles.size(); i++)
    {
        delete tiles[i];
    }
}