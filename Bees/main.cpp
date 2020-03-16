#include "Graphics.h"

int main()
{
    Graphics Game;

    Game.load(1, 0);

    while(Game.isOpen())
    {
        if(Game.isContinue())
            Game.gameLoop();
        else
            Game.gameOver();
    }
	return 0;
}
