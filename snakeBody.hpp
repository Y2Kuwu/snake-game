#ifndef SNAKEBODY_H
#define SNAKEBODY_H
#include <SFML/Graphics.hpp>
#include <iostream>

class snakeBody : public ::sf::Drawable
{
    public: 
    snakeBody(); //default

    void move();
    void addLength();
    void ouroboros();

};


#endif