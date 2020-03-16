#include "Text.h"

Text::Text()
{
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Error loading .ttf file" << std::endl;
    }
    text.setFont(font);
    text.setCharacterSize(CHARACTERSIZE);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Regular);

}

