#include "Animal.h"

Animal::Animal()
{
    timer.clock.restart();
    timer.plusminusone = rand() % 3 - 1;
    timer.timeout = rand() % ChangeAlphaBasicMovementTime;
}

void Animal::setVector(double x, double y)
{
    vector.x = x;
    vector.y = y;
}

void Animal::setPosition(double a, double b)
{
	if (a <= SCREENWIDTH - 2*size && 0 <= a)
		coordinates.x = a;
	if (b <= SCREENHEIGHT - 2*size && 0 <= b)
		coordinates.y = b;
    circle.setPosition(coordinates.x, coordinates.y);
}

std::vector<double> Animal::basicMovementsVector(double basicMovementVelocityParameter)
{
    check_timer();

    double alpha = atan2(vector.y, vector.x);

    alpha += timer.plusminusone * BasicMovementAlphaParam;

    //double length = sqrt(vector.x*vector.x + vector.y*vector.y);

    std::vector<double> basicMovements(2);
    basicMovements[0] = cos(alpha) * basicMovementVelocityParameter;
    basicMovements[1] = sin(alpha) * basicMovementVelocityParameter;
    return basicMovements;
}

void Animal::check_timer()
{
    if(timer.clock.getElapsedTime().asMilliseconds() >= timer.timeout)
        {
            timer.plusminusone = rand() % 3 - 1;
            timer.timeout = rand() % ChangeAlphaBasicMovementTime;
            timer.clock.restart();
        }
}
