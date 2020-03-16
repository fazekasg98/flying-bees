#include "Bees.h"
#include <iostream>


bool notForbidden(std::vector<int> forbidden, int x)
{
    for(int i=0; i<forbidden.size(); i++)
        if(forbidden[i] == x)
            return false;
    return true;
}

void randomFactor(double &x, double &y)
{
    double length = sqrt(x*x + y*y);
    double alpha = atan2(y, x) + (rand()%paramRand - paramRand/2)/100;
    x = length * cos(alpha);
    y = length * sin(alpha);
}

Animals::Animals()
{
	BeesArray.clear();
	WaspsArray.clear();
	FlowerArray.clear();
	//honey = 0;
}

void Animals::beesChooseFlower()
{
    for(int i=0; i<BeesArray.size();i++)
    {
    //std::cout << " bee: " << i;
        if(BeesArray[i].flower == -1 || BeesArray[i].flower >= FlowerArray.size())
        {
            //megkeresi a legkevesebbszer választott virágot
            int choosenFlowers[FlowerArray.size()];
            int min = 100000;
            int which = 0;

            for(int j=0; j<FlowerArray.size();j++)
            {
                choosenFlowers[j] = 0;
                //std::cout << " <" <<  choosenFlowers[j] << "> ";
            }

            for(int j=0; j<BeesArray.size(); j++)
                    if(BeesArray[j].flower < FlowerArray.size() && BeesArray[j].flower >= 0)
                        choosenFlowers[BeesArray[j].flower]++;

            //std::cout << " choosenFlowers: ";
            for(int j=0; j<FlowerArray.size(); j++)
            {
                //std::cout << choosenFlowers[j] << " ";
                if(choosenFlowers[j] < min)
                {
                    min = choosenFlowers[j];
                    which = j;
                    //std::cout << " min: " << min;
                }
            }
            BeesArray[i].flower = which;
            //std::cout << " BeesArray[i].flower: " << BeesArray[i].flower;
        }
    //std::cout << std::endl;
    }
    //std::cout << std::endl << std::endl;
}

void Animals::beesFindNewFlower()
{
    for(int i=0; i<BeesArray.size();i++)
        BeesArray[i].flower = -1;
    beesChooseFlower();
}

bool Animals::FlowerPush(int x, int y)
{
    if(FlowerArray.size() != FlowersNumMax)
    {
        Flower f(x, y);
        FlowerArray.push_back(f);
        std::cout << "FlowerArray size: " << FlowerArray.size() << std::endl;
        return true;
    }
    return false;
}

int Animals::FlowerPop(sf::Vector2i v)
{
    for(int i=0; i<FlowerArray.size(); i++)
        if((v.x >= FlowerArray[i].getcoordinates().x - FlowerImageDiff_x && v.x <= FlowerArray[i].getcoordinates().x + FlowerImageDiff_x) && (v.y >= FlowerArray[i].getcoordinates().y - FlowerImageDiff_y && v.y <= FlowerArray[i].getcoordinates().y + FlowerImageDiff_y) )
        {
            FlowerArray.erase(FlowerArray.begin()+i);

            //a kivett virágnál lévő méhek -1-et kapnak
            for(int j=0; j<BeesArray.size();j++)
            {
                if(BeesArray[j].flower == i)
                    BeesArray[j].flower = -1;
                if(BeesArray[j].flower > i)
                    BeesArray[j].flower--;
            }

            return i;
        }
    return -1;
}

bool Animals::Beespush()
{
	if (BeesArray.size() != BeesNumMax)
    {
        Bee b;
        BeesArray.push_back(b);
        return true;
    }
    return false;
}

bool Animals::Beespush(int x, int y)
{
    if (BeesArray.size() != BeesNumMax)
    {
        Bee b;
        b.setPosition(x, y);
        BeesArray.push_back(b);
        return true;
    }
    return false;
}

void Animals::Beespop()
{
	if (BeesArray.size() != 1)
		BeesArray.pop_back();
}

void Animals::WaspPop()
{
	if (WaspsArray.size() != 0)
		WaspsArray.pop_back();
}

bool Animals::Waspspush()
{
    if(WaspsArray.size() != WaspsNumMax)
    {
        Wasp w;
        WaspsArray.push_back(w);
        return true;
    }
    return false;
}

void Animals::setBeesVectors(sf::RenderWindow *window)
{
	//végiglépked az összes méhen
	for (int i = 0; i < BeesArray.size(); i++)
	{
		//számlálók
		double xCounter = 0;
		double yCounter = 0;

		//jelenlegi pozíció
		double xNow = BeesArray[i].getPosition_x();
		double yNow = BeesArray[i].getPosition_y();


        //bolyban mozgás
        if(FlowerArray.size() == 0)
        {
            //összeadja a többi pozícióját
            for(int j = 0; j < BeesArray.size(); j++)
                if (i != j)
                {
                    double diff_x = BeesArray[j].getPosition_x() - xNow;
                    double diff_y = BeesArray[j].getPosition_y() - yNow;

                    if(sqrt(diff_x*diff_x + diff_y * diff_y) > 30)
                    {
                        xCounter += diff_x;
                        yCounter += diff_y;
                    }
                    //távolodó mozgás
                    else
                    {
                        xCounter -= diff_x * 10;
                        yCounter -= diff_y * 10;
                    }
                }
            //megszorozza az adott paraméterekkel
            xCounter = (xCounter / (BeesArray.size())) * paramOtherBees;
            yCounter = (yCounter / (BeesArray.size())) * paramOtherBees;
        }

		//EGÉR
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            xCounter += (sf::Mouse::getPosition(*window).x - xNow) * paramCursor;
            yCounter += (sf::Mouse::getPosition(*window).y - yNow) * paramCursor;
        }

        //VIRÁGOK
        else
        {
            if(FlowerArray.size() != 0 && BeesArray[i].flower != -1)
            {
                //MÉZ

                //VEKTOROK
                xCounter += (FlowerArray[BeesArray[i].flower].getcoordinates().x - xNow) * paramFlowers;
                yCounter += (FlowerArray[BeesArray[i].flower].getcoordinates().y - yNow) * paramFlowers;
            }
        }




        //DARAZSAK
        for(int j=0; j<WaspsArray.size(); j++)
        {
            double difference_x = xNow - WaspsArray[j].getPosition_x();
            double difference_y = yNow - WaspsArray[j].getPosition_y();
            double sqrtdist = sqrt(sqrt(difference_x*difference_x + difference_y*difference_y));
            double alpha = atan2(difference_y, difference_x);
            xCounter += ((beeSize + waspSize) / sqrtdist) * cos(alpha) * paramWasps;
            yCounter += ((beeSize + waspSize) / sqrtdist) * sin(alpha) * paramWasps;
        }

        //ALAPMOZGÁS
        std::vector<double> basicMovements = BeesArray[i].basicMovementsVector(BEEBASICMOVEMENTPARAMETER);
        xCounter += basicMovements[0];
        yCounter += basicMovements[1];

        //TÁVOLSÁGTARTÁS A SZÉLÉTŐL
        {
            if(xNow + (xCounter * paramWallMultiplication) < 0)
            {
                xCounter -= xNow + (xCounter * paramWallMultiplication);
                BeesArray[i].changePlusMinusOne();
            }

            if(yNow + (yCounter * paramWallMultiplication) < 0)
            {
                yCounter -= yNow + (yCounter * paramWallMultiplication);
                BeesArray[i].changePlusMinusOne();
            }

            if(xNow + (xCounter * paramWallMultiplication) > SCREENWIDTH)
            {
                xCounter -= xNow + (xCounter * paramWallMultiplication) - SCREENWIDTH;
                BeesArray[i].changePlusMinusOne();
            }
            if(yNow + (yCounter * paramWallMultiplication) > SCREENHEIGHT)
            {
                yCounter -= yNow + (yCounter * paramWallMultiplication) - SCREENHEIGHT;
                BeesArray[i].changePlusMinusOne();
            }
        }

        xCounter *= BEEVELOCITYPARAMETER;
        yCounter *= BEEVELOCITYPARAMETER;

		BeesArray[i].setVector(xCounter, yCounter);
	}
}

void Animals::setBeesPositions()
{
	for (int i = 0; i < BeesArray.size(); i++)
	{
		BeesArray[i].setPosition(BeesArray[i].getPosition_x() + BeesArray[i].getVector_x(), BeesArray[i].getPosition_y() + BeesArray[i].getVector_y());
	}

}

void Animals::setWaspsVectors()
{
    double distance;
    double vector_x, vector_y;
    double diff_x, diff_y;
    std::vector<int> forbidden;

    //HA MEGETTÉK AZ ÖSSZES MÉHET
    if(BeesArray.size() == 0)
    {
        for(int i=0; i<WaspsArray.size(); i++)
        {
            WaspsArray[i].setVector(0, 0);
        }
        return;
    }

    //HA KEVESEBB MÉH VAN, MINT DARÁZS
    if(WaspsArray.size() > BeesArray.size())
    {
        for(int i=0; i<BeesArray.size(); i++)
        {
            forbidden.push_back(-1);
            double mindistance = 10000;
            double witchWasp;
            for(int j=0; j<WaspsArray.size(); j++)
            {
                if(notForbidden(forbidden, j))
                {
                    diff_x = BeesArray[i].getPosition_x() - WaspsArray[j].getPosition_x();
                    diff_y = BeesArray[i].getPosition_y() - WaspsArray[j].getPosition_y();
                    distance = sqrt(diff_x*diff_x + diff_y*diff_y);

                    if(distance <= beeSize + waspSize)
                    {
                        BeesArray.erase(BeesArray.begin() + j);
                        break;
                    }

                    if(distance < mindistance)
                    {
                        witchWasp = j;
                        forbidden[i] = witchWasp;
                        mindistance = distance;
                        vector_x = diff_x;
                        vector_y = diff_y;
                    }
                }
            }
            double alpha = atan2(vector_y, vector_x);
            WaspsArray[witchWasp].setVector(cos(alpha) * WASPVELOCITYPARAMETER, sin(alpha) * WASPVELOCITYPARAMETER);
            }

        // A KI NEM VÁLASZOTT DARAZSAK BASIC MOZGÁST KAPNAK
        for(int i=0; i<WaspsArray.size();i++)
            if(notForbidden(forbidden, i) == true)
            {
                WaspsArray[i].setVector(WaspsArray[i].basicMovementsVector(WASPBASICMOVEMENTPARAMETER)[0], WaspsArray[i].basicMovementsVector(WASPBASICMOVEMENTPARAMETER)[1]);
            }
    }


    //HA TÖBB MÉH VAN, MIN DARÁZS
    else
        for(int i=0; i<WaspsArray.size(); i++)
        {
            forbidden.push_back(-1);
            double minDistance = 10000;
            for(int j=0; j<BeesArray.size(); j++)
            {
                if(notForbidden(forbidden, j))
                {
                    diff_x = BeesArray[j].getPosition_x() - WaspsArray[i].getPosition_x();
                    diff_y = BeesArray[j].getPosition_y() - WaspsArray[i].getPosition_y();
                    distance = sqrt(diff_x*diff_x + diff_y*diff_y);

                    if(distance <= beeSize + waspSize)
                    {
                        BeesArray.erase(BeesArray.begin() + j);
                        break;
                    }
                    if(minDistance > distance)
                    {
                        forbidden[i] = j;
                        minDistance = distance;
                        vector_x = diff_x;
                        vector_y = diff_y;
                    }
                }

                double alpha = atan2(vector_y, vector_x);
                WaspsArray[i].setVector(cos(alpha) * WASPVELOCITYPARAMETER, sin(alpha) * WASPVELOCITYPARAMETER);
            }
        }
    //std::cout << std::endl;
    /*std::cout << "forbiddens: ";
    for(int i=0; i<forbidden.size(); i++)
        std::cout << forbidden[i] << " ";
    std::cout << std::endl;*/


}

void Animals::setWaspsPositions()
{
    for(int i=0; i<WaspsArray.size(); i++)
        WaspsArray[i].setPosition(WaspsArray[i].getPosition_x() + WaspsArray[i].getVector_x(), WaspsArray[i].getPosition_y() + WaspsArray[i].getVector_y());
}

void Animals::moving(sf::RenderWindow *window)
{
    setWaspsVectors();
	setWaspsPositions();
	setBeesVectors(window);
	setBeesPositions();


    for(int i=0; i<WaspsArray.size(); i++)
        WaspsArray[i].draw(window);

    for(int i=0; i<BeesArray.size(); i++)
        BeesArray[i].draw(window);
}

void Animals::waspsDraw(sf::RenderWindow *window)
{
    for(int i=0; i<WaspsArray.size(); i++)
        WaspsArray[i].draw(window);
}


