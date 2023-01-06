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
//std::vector<sf::CircleShape>snackSack;
//sf::FloatRect bounds;
float sz = 6;

sf::FloatRect globals;

public:

explicit Snacks(sf::Vector2f snackPos);
//Snacks() = default;
sf::CircleShape getSnack();
sf::Vector2f getBounds(); 
void upd();
void setBounds(sf::Vector2f newPos);
// {
//     return snackBounds1;
// }

// void SetBounds1(sf::Vector2f pos1);
// // {
// //     snackBounds1 = pos1;
// // }

// sf::Vector2f GetBounds2(); 
// // {
// //     return snackBounds1;
// // }

// void SetBounds2(sf::Vector2f pos2);
// // {
// //     snackBounds2 = pos2;
// // }

// void SetPos1();
// // {
// //     snack.setPosition(snackBounds1);
// // }

// void SetPos2();
// // {
// //     snack.setPosition(snackBounds2);
// // }

// sf::Vector2f SnackPos();
// {
//    return snack.getPosition();
// }






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





// class Collision 

// {
// sf::RectangleShape collide;
// sf::Vector2f impactBounds;
// sf::Vector2f backSz;
// sf::CircleShape snax;

// public:

// sf::FloatRect globals;
// Collision(sf::Vector2f snackPos);
// sf::RectangleShape getCollision();
// void setImpact(sf::Vector2f newPos); 
// void upd();
// sf::Vector2f getImpact();
// {
//     return impactBounds1;
// }

// void SetImpactBounds1(sf::Vector2f impact1);
// // {
// //     impactBounds1 = impact1;
// // }

// void SetImpact1();
// // {
// //     collide.setPosition(impactBounds1);
// // }

// sf::Vector2f GetImpact2(); 
// // {
// //     return impactBounds2;
// // }

// void SetImpactBounds2(sf::Vector2f impact2);
// // {
// //     impactBounds2 = impact2;
// // }

// void SetImpact2();
// // {
// //     collide.setPosition(impactBounds2);
// // }


// // sf::FloatRect GetBox()
// // {
// //     return globals;
// // }

// // void RandSnackLoc()
// // {
// //     srand(time(NULL));
// // }




// void bgTest(sf::RenderWindow &win)
// {
//     win.draw(collide);
// }


};
#endif