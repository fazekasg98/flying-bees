#pragma once
#include "Texts.h"

class Graphics
{
private:
    sf::RenderWindow window;
    Animals animals;
    Texts texts;

    Background lawn;

    sf::Texture flowerTexture;
    vector<sf::Sprite> flowers;

    sf::Clock stopper;

public:
	Graphics();
	bool isOpen() {return window.isOpen();};
	void load(int beesNumber, int WaspsNumber);
	bool isContinue();
	void gameLoop();
	void gameOver();
	void drawImages();
	void pushFlower(int, int);
	void popFlower(sf::Vector2i);
	~Graphics();
};

