#include "Flower.h"

Flower::Flower(int x, int y)
{
    timer.plusminusone = rand() % 2;
    //std::cout << timer.plusminusone << std::endl;
    timer.timeout = rand() % ChangeNectarTime;
    timer.clock.restart();

    coordinates.x = x;
    coordinates.y = y;

    //flower.setRadius(flowerSize);
    //flower.setFillColor(sf::Color(rand()%100 + 155, rand()%100 + 155, 0));

    /*sprite.setTexture(flower);
    sprite.setPosition(coordinates.x, coordinates.y);*/
}

bool Flower::isNectar()
{
    checkTimer();
    if(timer.plusminusone == 1)
        return true;
    else
        return false;
}

void Flower::checkTimer()
{
    if(timer.clock.getElapsedTime().asSeconds() >= timer.timeout)
        {
            timer.plusminusone = rand() % 2;
            std::cout << timer.plusminusone << std::endl;
            timer.timeout = rand() % ChangeNectarTime;
            timer.clock.restart();
        }
}
