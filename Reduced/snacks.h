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
sf::Vector2f FoodLocation()
{
    return snackPos;
}

void GetLocation(sf::Vector2f postion)
{
    postion = snackPos;
    FoodLocation();
}



Snacks(float sz, sf::Vector2f pos)
{
    snack.setRadius(sz);
    snack.setPosition(pos);
    snack.setFillColor(sf::Color::Red);
    snack.setOutlineColor(sf::Color::Black);
    snack.setOutlineThickness(2);
}



// void setSnackPos(float x , float y)
// {
//     snackX = x;
//     snackY = y;
//     totalRendered +=1;
// }
// float getSnackPos()
// {
//     return snackX,snackY;
// }

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
    win.draw(snack);
    
}




};
#endif