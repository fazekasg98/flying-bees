#include "Graphics.h"



Graphics::Graphics()
{
    stopper.restart();
    //elapsedTime = 0;

    window.create(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Flying Bees");
    window.setFramerateLimit(60);

    if (!flowerTexture.loadFromFile("Flower.png"))
    {
        std::cout << "Error of loading image" << std::endl;
    }

    if (!lawn.texture.loadFromFile("lawn2.jpg"))
    {
        std::cout << "Error of loading image" << std::endl;
    }

    lawn.sprite.setTexture(lawn.texture);
    lawn.sprite.setPosition(0,0);
    lawn.sprite.setScale(0.6, 0.6);
    lawn.sprite.setColor(sf::Color(0, 150, 0));
}

bool Graphics::isContinue()
{
    if(animals.getBeesNum() == 0)
        return false;
    return true;
}

void Graphics::load(int beesNumber, int WaspsNumber)
{

    for(int i=0; i<beesNumber; i++)
        animals.Beespush();
    for(int i=0; i<WaspsNumber; i++)
        animals.Waspspush();

    /*pushFlower(SCREENWIDTH / 2, SCREENHEIGHT / 3);
    pushFlower(SCREENWIDTH / 3, SCREENHEIGHT / 2);
    pushFlower(SCREENWIDTH / 4, SCREENHEIGHT / 4);*/
}

void Graphics::gameLoop()
{

    sf::Event event;
    window.clear();
    window.draw(lawn.sprite);
    if((sf::Mouse::isButtonPressed(sf::Mouse::Left) == 0 && animals.getBeesNum() == BeesNumMax) || sf::Mouse::isButtonPressed(sf::Mouse::Right) == 1)
        texts.changeColorNUMBER(sf::Color::White);

    while (window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::MouseButtonPressed:
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    pushFlower(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    animals.beesChooseFlower();
                }
                if(event.mouseButton.button == sf::Mouse::Right)
                {
                    popFlower(sf::Mouse::getPosition(window));
                    animals.beesChooseFlower();
                }
                break;
            }

            case sf::Event::KeyPressed:
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    animals.beesFindNewFlower();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    animals.Waspspush();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
                    animals.WaspPop();

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    if(animals.Beespush() == false)
                        texts.changeColorNUMBER(sf::Color::Red);
                    else
                        animals.beesChooseFlower();
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    animals.Beespop();
                    animals.beesChooseFlower();
                }
                break;
            }

            case sf::Event::Closed:
                {window.close(); break;}
        }
    }
    drawImages();
    //animals.flowersDraw(&window);
    texts.draw(&window, animals, stopper.getElapsedTime().asSeconds());
    animals.moving(&window);

    window.display();
}

void Graphics::drawImages()
{
    for(int i=0; i<flowers.size(); i++)
        window.draw(flowers[i]);
}

void Graphics::gameOver()
{
    sf::Event event;
    window.clear();
    window.draw(lawn.sprite);
    while (window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                {window.close(); break;}

            case sf::Event::KeyPressed:
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    stopper.restart();
                    animals.clearWaspsArray();
                    animals.clearFlowerArray();
                    flowers.clear();
                    load(1,0);
                }
                break;
            }
        }
    }
    animals.waspsDraw(&window);

    texts.draw_gameOver(&window);
    window.display();
}


void Graphics::pushFlower(int x, int y)
{
    sf::Sprite f;
    f.setTexture(flowerTexture);
    f.setPosition(x - 23, y - 22);
    f.setScale(0.03, 0.03);
    f.setColor(sf::Color(150, 150, 0));
    flowers.push_back(f);

    animals.FlowerPush(x, y);
}

void Graphics::popFlower(sf::Vector2i v)
{
    int kivenni = animals.FlowerPop(v);
    if(kivenni != -1)
        flowers.erase(flowers.begin() + kivenni);
}

Graphics::~Graphics()
{
    window.close();
}
