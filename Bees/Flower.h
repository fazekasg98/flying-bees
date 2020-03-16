#ifndef FLOWER_H
#define FLOWER_H
#include "Includes&Parameters&Structs.h"

class Flower
{
private:
    Parameters coordinates;
    Timer timer;
public:
    Flower(int x, int y);
    inline bool isNectar();
    inline Parameters getcoordinates() {return coordinates;}
    void checkTimer();
};

#endif // FLOWER_H
