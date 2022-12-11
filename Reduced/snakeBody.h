#ifndef SNAKE_H
#define SNAKE_H
#include<SFML/Graphics.hpp>
#include"snacks.h"
class Snake
{
private:
int len = 3;
int consumption = 0;
int speed;
sf::Vector2f pos;
float x , y;
sf::RectangleShape bodySegment;
std::vector<sf::RectangleShape>snakeBody;

public:

void setLen(int lengthOf, int consumed)
{
    len = lengthOf;
    consumption = consumed;
}
int getLen()
{
    return len , consumption;
}

void setPos(float xPos , float yPos)
{
    x = xPos;
    y = yPos;
    pos.x = x;
    pos.y = y;
}
sf::Vector2f getPos()
{
    return pos;
}

// void hungry()
// {
//     if()
// }




};


#endif