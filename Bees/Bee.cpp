#include "Bee.h"

Bee::Bee()
{
    size = beeSize;

    flower = -1;

    /*timer.clock.restart();
    timer.plusminusone = rand() % 3 - 1;
    timer.timeout = rand() % ChangeAlphaBasicMovementTime;*/

    circle.setRadius(size);
    circle.setFillColor(sf::Color(255, 190, 0));

	coordinates.x = rand() % (SCREENWIDTH - 2*size);
	coordinates.y = rand() % (SCREENHEIGHT - 2*size);

	vector.x = rand()%49;
	vector.y = rand()%49;

	circle.setPosition(coordinates.x, coordinates.y);
}

/*std::vector<double> Bee::basicMovementsVector()
{
    check_timer();

    double alpha = atan2(vector.y, vector.x);

    alpha += timer.plusminusone * BasicMovementAlphaParam;

    double length = sqrt(vector.x*vector.x + vector.y*vector.y);

    std::vector<double> basicMovements(2);
    basicMovements[0] = cos(alpha) * 5;
    basicMovements[1] = sin(alpha) * 5;
    return basicMovements;
}*/

/*void Bee::check_timer()
{
    if(timer.clock.getElapsedTime().asMilliseconds() >= timer.timeout)
        {
            timer.plusminusone = rand() % 3 - 1;
            timer.timeout = rand() % ChangeAlphaBasicMovementTime;
            timer.clock.restart();
        }
}*/

void Bee::changePlusMinusOne()
{
    if(timer.plusminusone == 1)
        timer.plusminusone = -1;
    if(timer.plusminusone == -1)
        timer.plusminusone = 1;
}

