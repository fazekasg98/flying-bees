#ifndef TEXTS_H
#define TEXTS_H
#include "Text.h"


class Texts
{
private:
    Text numBeesNUMBER;
    Text numBeesTEXT;
    Text numWaspsNUMBER;
    Text numWaspsTEXT;
    Text gameOver;
    Text playAgain;
    Text stopper_seconds;

public:
    Texts();
    void draw(sf::RenderWindow *window, Animals bees ,double elapsedTime);
    void changeColorNUMBER(sf::Color color) {numBeesNUMBER.changeColor(color); return;};
    void draw_gameOver(sf::RenderWindow *window);
};

#endif // TEXTS_H
