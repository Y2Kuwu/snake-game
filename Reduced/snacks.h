#ifndef SNACKS_H
#define SNACKS_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include <stdlib.h>

class Snacks{
private:
int points;
int totalRendered;
float snackX , snackY;
sf::Vector2f snackBounds1;
sf::Vector2f snackBounds2;
sf::CircleShape snack;
std::vector<sf::CircleShape>snackSack;
//sf::FloatRect bounds;

public:
Snacks() = default;
sf::Vector2f GetBounds1() 
{
    return snackBounds1;
}

void SetBounds1(sf::Vector2f pos1)
{
    snackBounds1 = pos1;
}

sf::Vector2f GetBounds2() 
{
    return snackBounds1;
}

void SetBounds2(sf::Vector2f pos2)
{
    snackBounds2 = pos2;
}

void SetPos1()
{
    snack.setPosition(snackBounds1);
}

void SetPos2()
{
    snack.setPosition(snackBounds2);
}


Snacks(float sz)
{
    snack.setRadius(sz);
    //snack.setPosition(spos);
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
    //snack.setPosition(snackBounds1);
    win.draw(snack);
    
}


};

class Collision : private Snacks

{
sf::RectangleShape collide;
sf::Vector2f impactBounds1;
sf::Vector2f impactBounds2;
sf::Vector2f backSz;

public:

Collision() = default;

sf::FloatRect globals;



void SetImpactBounds1(sf::Vector2f impact1)
{
    impactBounds1 = impact1;
}

void SetImpact1()
{
    collide.setPosition(impactBounds1);
}



void SetImpactBounds2(sf::Vector2f impact2)
{
    impactBounds2 = impact2;
}
void SetImpact2()
{
    collide.setPosition(impactBounds2);
}

sf::Vector2f GetImpact1() 
{
    return impactBounds1;
}

sf::Vector2f GetImpact2() 
{
    return impactBounds2;
}
// sf::FloatRect GetBox()
// {
//     return globals;
// }

// void RandSnackLoc()
// {
//     srand(time(NULL));
// }


Collision(sf::Vector2f backSz)
{
    collide.setSize(backSz);
    //collide.setPosition(backPos);
    collide.setOutlineColor(sf::Color::Black);
    collide.setOutlineThickness(2);
    collide.setFillColor(sf::Color::Black);
    globals = collide.getGlobalBounds();
}

void bgTest(sf::RenderWindow &win)
{
    win.draw(collide);
    
}


};
#endif