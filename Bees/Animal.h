#ifndef ANIMAL_H
#define ANIMAL_H
#include "Includes&Parameters&Structs.h"



class Animal
{
    protected:
        int size;
        sf::CircleShape circle;
        Parameters coordinates;
        Parameters vector;
        Timer timer;

    public:
        Animal();
        void setPosition(double x, double y);
        inline double getPosition_x() { return coordinates.x; }
        inline double getPosition_y() { return coordinates.y; }

        void setVector(double x, double y);
        inline double getVector_x() { return vector.x; }
        inline double getVector_y() { return vector.y; }

        inline void draw(sf::RenderWindow *window) { window->draw(circle); return;}
        std::vector<double> basicMovementsVector(double basicMovementVelocityParameter);
        void check_timer();
};

#endif // ANIMAL_H
