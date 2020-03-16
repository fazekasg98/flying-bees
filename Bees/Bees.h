#pragma once
#include "Bee.h"
#include "Wasp.h"
#include "Flower.h"

using namespace std;

class Animals
{
private:
	std::vector<Bee> BeesArray;
	std::vector<Wasp> WaspsArray;
	std::vector<Flower> FlowerArray;
	//double honey;

public:
	Animals();
	bool FlowerPush(int x, int y);
	int FlowerPop(sf::Vector2i);
	bool Beespush();
	bool Beespush(int x, int y);
	void Beespop();
	bool Waspspush();
	void WaspPop();
	void setBeesVectors(sf::RenderWindow *window);
	void setBeesPositions();
	void setWaspsVectors();
	void setWaspsPositions();
	inline int getBeesNum() {return BeesArray.size();}
	inline int getWaspsNum() {return WaspsArray.size();}
	void moving(sf::RenderWindow *window);
	void waspsDraw(sf::RenderWindow *window);
	inline void clearWaspsArray() {WaspsArray.clear();}
	inline void clearFlowerArray() {FlowerArray.clear();}
	void beesChooseFlower();
	void beesFindNewFlower();
};

