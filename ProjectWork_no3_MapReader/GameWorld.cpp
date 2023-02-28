#include "GameWorld.h"
#include "bitmap_image.hpp"

GameWorld::GameWorld(int _viewDistance,const int _textureSize,sf::RenderWindow* _window)
{
    window = _window;
    textureSize = _textureSize;
    viewDistance = _viewDistance;
    drawAbleSprite();
    readFromMap();
    scale = setScale();

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
                tiles.push_back(new GameTile(x, y, 100, textures[1]));
                center = new Center(x, y);
            }
            else
            {
                tiles.push_back(new GameTile(x, y, id,textures[1]));
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

        int minX = center->pos.x - (viewDistance/2);
        int maxX = center->pos.x + (viewDistance/2);
        int minY = center->pos.y - (viewDistance/2);
        int maxY = center->pos.y + (viewDistance/2);
        int X = tiles[i]->pos.x;
        int Y = tiles[i]->pos.y;
        if (X >= minX && X <= maxX )
        {
            if (Y >= minY && Y <= maxY)
            {
                tiles[i]->setSpritePos(minX, minY);
                window->draw(tiles[i]->getSprite(scale));
                center->setSpritePos(minX, minY);
                window->draw(center->getSprite(scale));
            }
        }
    }
    if (isToolBarChosed)
    {
        sf::RectangleShape square(sf::Vector2f(50, 150));
        square.setPosition(50, 150);
        square.setSize(sf::Vector2f(650, 400));
        square.setFillColor(sf::Color(0,0,0));
        window->draw(square);
        int a=1;
        int b=1;
        for (int i = 1; i < textures.size(); i++)
        {
            sf::Sprite sprite;
            sprite.setTexture(textures[i]);
            sprite.setPosition(a*60,100+(b*60));
            window->draw(sprite);
            a++;
            if (a>12)
            {
                a = 1;
                b++;
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
    int i = 0;
    while (i<1000)
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            center->pos.x++;
            break;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            center->pos.x--;
            break;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            center->pos.y++;
            break;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            center->pos.y--;
            break;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
        {
            if (viewDistance < 15)
            {
                viewDistance += 2;
            }
            break;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
        {

            if (viewDistance > 5)
            {
                viewDistance -= 2;
                break;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
        {
            isToolBarChosed = !isToolBarChosed;
            break;
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (isToolBarChosed)
            {
                sf::Vector2i mousePos(sf::Mouse::getPosition(*window));
                int x= (mousePos.x)/60;
                int y= (mousePos.y-100)/60;
                int id = x + (y-1) * 12;
                if (id > 0 && id < textures.size())
                {
                    curentPlacing = &textures[id];
                }
                break;
            }
            else
            {

            }
        }
        i++;
    }
}

void GameWorld::drawAbleSprite()
{

    dr("error.png");
    dr("grass.png");
    dr("water.png");
}
void GameWorld::dr(const std::string& pngname) {
    sf::Texture texture;
    texture.loadFromFile(pngname);
    textures.push_back(texture);
}

GameWorld::~GameWorld()
{
    for (int i = 0; i < tiles.size(); i++)
    {
        delete tiles[i];
    }
    delete center;
}