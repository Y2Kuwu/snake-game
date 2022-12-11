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
Snake() = default;
Snake(sf::Vector2f size, sf::Vector2f firstPos)
{
    bodySegment.setSize(size);
    bodySegment.setFillColor(sf::Color::Green);
    bodySegment.setOutlineColor(sf::Color::Black);
    bodySegment.setOutlineThickness(2);
    bodySegment.setPosition(firstPos);
}


void setLen(int consumed)
{
    //len = lengthOf;
    consumption = consumed;
}
int getLen()
{
    return consumption;
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

void DrawBody(sf::RenderWindow &win)
{
    win.draw(bodySegment);
}

// void hungry()
// {
//     if()
// }




};


#endif