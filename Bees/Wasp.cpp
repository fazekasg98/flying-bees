#include "Wasp.h"



Wasp::Wasp()
{
    size = waspSize;

    circle.setRadius(size);
    circle.setFillColor(sf::Color(0, 0, 102));

    int come = rand() % 4;

    switch(come)
    {
    case 0:
        {
            coordinates.x = 0;
            coordinates.y = rand() % SCREENHEIGHT;
            break;
        }
    case 1:
        {
            coordinates.x = rand() % SCREENWIDTH;
            coordinates.y = waspSize;
            break;
        }
    case 2:
        {
            coordinates.x = SCREENWIDTH - 3*waspSize;
            coordinates.y = rand() % SCREENHEIGHT;
            break;
        }
    case 3:
        {
            coordinates.x = rand() % SCREENWIDTH - 2*waspSize;
            coordinates.y = SCREENHEIGHT - 2*waspSize;
            break;
        }
    }

	vector.x = 0;
	vector.y = 0;

	circle.setPosition(coordinates.x, coordinates.y);
}
