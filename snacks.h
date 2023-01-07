#ifndef SNACKS_H
#define SNACKS_H 

#include<SFML/Graphics.hpp>
#include<iostream>
#include <stdlib.h>
#include "snakeBody.h"

class Snacks{
private:
int points;
int totalRendered;
float snackX , snackY;
sf::Vector2f snackBounds;
sf::CircleShape snack;

sf::RectangleShape collide;
float sz = 6;
sf::FloatRect globals;

public:

explicit Snacks(sf::Vector2f snackPos);
sf::CircleShape getSnack();
sf::Vector2f getBounds(); 
void upd();
void setBounds(sf::Vector2f newPos);



};
#endif