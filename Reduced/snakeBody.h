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

bool left;
bool right;
bool up;
bool down;

int add = 0;

sf::Event evt;

public:


Snake() = default;
Snake(sf::Vector2f size, sf::Vector2f currPos)
{
    bodySegment.setSize(size);
    bodySegment.setFillColor(sf::Color::Green);
    bodySegment.setOutlineColor(sf::Color::Black);
    bodySegment.setOutlineThickness(6);
    bodySegment.move(currPos);
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

void setPos(sf::Vector2f position)
{
    // x = position.x;
    // y = position.y;
    // pos.x = x;
    // pos.y = y;
    pos = position;
}
sf::Vector2f getPos()
{
    return pos;
}

void direction(sf::Event e, float delta)
{
    evt = e;
    if(e.key.code == sf::Keyboard::Left || evt.key.code == sf::Keyboard::A)
    {
        left = true;
        vel.x = -50.0f;
        vel.y = 0.0f;
      
        
    }
    else if(e.key.code == sf::Keyboard::Right && evt.KeyReleased|| evt.key.code == sf::Keyboard::D)
    {
        right = true;
        vel.x = 50.0f;
        vel.y = 0.0f;
       
        
    }
    else if(e.key.code == sf::Keyboard::Up || evt.key.code == sf::Keyboard::W)
    {
        up = true;
        vel.x = 0.0f;
        vel.y = -50.0f;
    }
    else if(e.key.code == sf::Keyboard::Down || evt.key.code == sf::Keyboard::D)
    {
        down = true;
        vel.x = 0.0f;
        vel.y = 50.0f;
        
        
    }
    pos += vel * delta;
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