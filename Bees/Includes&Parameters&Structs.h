#ifndef INCLUDES&PARAMETERS&STRUCTS_H_INCLUDED
#define INCLUDES&PARAMETERS&STRUCTS_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <vector>
#include "math.h"

int const beeSize = 4;
int const waspSize = 7;
int const flowerSize = 12;

double const paramWallMultiplication = 10;

int const paramRand = 300;
int const BeesNumMax = 100;
int const WaspsNumMax = 10;
int const FlowersNumMax = 10;

double const paramOtherBees = 0.009;
double const paramCursor = 0.01;
double const paramWasps = 1;//5
double const paramOtherWasps = 0.5;
double const paramFlowers = 0.01;
double const BasicMovementAlphaParam = 0.1;
int const ChangeAlphaBasicMovementTime = 400;
int const ChangeNectarTime = 60;

double const BEEVELOCITYPARAMETER = 0.7;
double const BEEBASICMOVEMENTPARAMETER = 5;
double const WASPBASICMOVEMENTPARAMETER = 2;
double const WASPVELOCITYPARAMETER = 6.5; //5.5

int const CHARACTERSIZE = 20;

int const SCREENWIDTH = 1000;
int const SCREENHEIGHT = 650;

int const FlowerImageDiff_x = 23;
int const FlowerImageDiff_y = 22;


struct Parameters {	double x, y; };

struct Timer {sf::Clock clock; int plusminusone; int timeout;};

struct Image {sf::Sprite sprite; Parameters coordinates;};

struct Background {sf::Sprite sprite; sf::Texture texture;};

//sf::Texture flowerTexture;

#endif // INCLUDES&PARAMETERS&STRUCTS_H_INCLUDED
