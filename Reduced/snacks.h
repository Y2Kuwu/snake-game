#ifndef SNACKS_H
#define SNACKS_H
#include<SFML/Graphics.hpp>
#include<iostream>

class Snacks{
private:
int points;
int totalRendered;
float snackX , snackY;
sf::Vector2f snackBounds;
sf::CircleShape snack;
std::vector<sf::CircleShape>snackSack;
//sf::FloatRect bounds;

public:
Snacks() = default;
sf::Vector2f GetBounds() 
{
    return snackBounds;
}

void SetBounds(sf::Vector2f pos)
{
    snackBounds = pos;
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

class Collision : private Snacks

{
sf::RectangleShape collide;
sf::Vector2f snackBack;
sf::Vector2f backSz;

public:

Collision() = default;

sf::FloatRect globals;

sf::Vector2f GetBack() 
{
    return snackBack;
}

void SetBack(sf::Vector2f back)
{
    snackBack = back;
}

sf::FloatRect GetBox()
{
    return globals;
}


Collision(sf::Vector2f backSz , sf::Vector2f backPos)
{
    collide.setSize(backSz);
    collide.setPosition(backPos);
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