#include "GameWorld.h"
#include "bitmap_image.hpp"

GameWorld::GameWorld(int _viewDistance)
{
    viewDistance = _viewDistance;

    window = new sf::RenderWindow(sf::VideoMode(50 * viewDistance, 50 * viewDistance), "game");

    readFromMap();
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
                tiles.push_back(new GameTile(x, y, 1));
                center = tiles[tiles.size() - 1];
            }
            else
            {
                tiles.push_back(new GameTile(x, y, id));
            }
        }
    }
}

GameWorld::~GameWorld()
{
    delete window;
    for (int i = 0; i < tiles.size(); i++)
    {
        delete tiles[i];
    }
}