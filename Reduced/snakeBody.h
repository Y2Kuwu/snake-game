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
sf::Vector2f vel;

float x , y;
sf::RectangleShape bodySegment;
std::vector<sf::RectangleShape>snakeBody;



sf::Event evt;

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

void direction(sf::Event e, float delta)
{
    evt = e;
    if(evt.key.code == sf::Keyboard::Left || evt.key.code == sf::Keyboard::A)
    {
        vel.x = -4.0f;
        vel.y = 0.0f;
        pos += vel * delta;
        setPos(pos.x , pos.y);
        std::cout << "Left";
    }

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