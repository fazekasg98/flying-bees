#ifndef TEXT_H
#define TEXT_H

#include "Bees.h"

class Text
{
private:
    sf::Font font;
    sf::Text text;

public:
    Text();
    void setPosition(int x, int y) {text.setPosition(x, y);}
    void setSize(double x) {text.setCharacterSize(x);}
    void setString(std::string s) {text.setString(s);}
    void draw(sf::RenderWindow *window) {window->draw(text);}
    void changeColor(sf::Color color) {text.setFillColor(color);}
};

#endif // TEXT_H
