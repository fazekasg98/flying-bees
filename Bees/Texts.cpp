#include "Texts.h"

Texts::Texts()
{
    gameOver.setSize(3*CHARACTERSIZE);
    playAgain.setSize(0.5*CHARACTERSIZE);

    numBeesNUMBER.setPosition(10 + (CHARACTERSIZE - 10) * 16, SCREENHEIGHT - CHARACTERSIZE - 10);
    numBeesTEXT.setPosition(10, SCREENHEIGHT - CHARACTERSIZE - 10);
    numWaspsNUMBER.setPosition(SCREENWIDTH - 20, SCREENHEIGHT - CHARACTERSIZE - 10);
    numWaspsTEXT.setPosition(SCREENWIDTH - 190, SCREENHEIGHT - CHARACTERSIZE - 10);
    gameOver.setPosition(SCREENWIDTH / 2 - 185, SCREENHEIGHT / 2 - CHARACTERSIZE/2);
    playAgain.setPosition(SCREENWIDTH / 2 - 75, SCREENHEIGHT - CHARACTERSIZE - 10);
    stopper_seconds.setPosition(SCREENWIDTH / 2 - 40, 10);

    numBeesTEXT.setString("Number of bees: ");
    numWaspsTEXT.setString("Number of wasps: ");
    gameOver.setString("GAME OVER");
    playAgain.setString("Press ENTER to play again");
}

void Texts::draw(sf::RenderWindow *window, Animals animals, double elapsedTime)
{
    numBeesNUMBER.setString(std::to_string(animals.getBeesNum()));
    numWaspsNUMBER.setString(std::to_string(animals.getWaspsNum()));
    stopper_seconds.setString(std::to_string(elapsedTime));

    numBeesNUMBER.draw(window);
    numBeesTEXT.draw(window);
    numWaspsNUMBER.draw(window);
    numWaspsTEXT.draw(window);
    stopper_seconds.draw(window);
}

void Texts::draw_gameOver(sf::RenderWindow *window)
{
    stopper_seconds.draw(window);
    gameOver.draw(window);
    playAgain.draw(window);
}
