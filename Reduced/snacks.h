#ifndef SNACKS_H
#define SNACKS_H
#include<SFML/Graphics.hpp>
#include<iostream>

class Snacks{
private:
int points;
int totalRendered;
float snackX , snackY;
sf::Vector2f snackPos;
sf::CircleShape snack;
std::vector<sf::CircleShape>snackSack;

public:
//Snacks() = default;
Snacks(float sz)
{
    this->snack.setRadius(sz);
    this->snack.setPosition(snackX,snackY);
    this->snack.setFillColor(sf::Color::Red);
    this->snack.setOutlineColor(sf::Color::Black);
}

void setSnackPos(float x , float y)
{
    snackX = x;
    snackY = y;
    totalRendered +=1;
}
float getSnackPos()
{
    return snackX,snackY;
}

void countSnacks()
{
   

    // if(totalRendered <= 3)
    // {
    //     snackSack.push_back(snack);
    // }
}

// int snackCount()
// {
//     return totalRendered;
// }

void makeSnacks(sf::RenderWindow &win)
{
    win.draw(this->snack);
    
}




};
#endif