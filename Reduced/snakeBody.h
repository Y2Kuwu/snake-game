#ifndef SNAKE_H
#define SNAKE_H
#include<SFML/Graphics.hpp>
#include"snacks.h"
class Snake
{
private:
//int len = 3;
//
//length == consumption

int consumption = 1; // 
//
int count = 0;
int speed;

sf::Vector2f rectsize;
sf::Vector2f pos;

sf::Vector2f prevPos;

sf::Vector2f segPos;
sf::Vector2f vel;
sf::Vector2f velDelay;

float x , y;
sf::RectangleShape bodySegment;
std::vector<sf::RectangleShape>snakeBody;
std::vector<sf::Vector2f>prevLocation;

bool left;
bool right;
bool up;
bool down;

bool traj;
bool updLen;

int add = 0;

sf::Event evt;

sf::Vector2f sz;
sf::RenderWindow *r;

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


sf::RectangleShape createBody(sf::Vector2f size , sf::Vector2f currPos)
{
    sf::RectangleShape body;
    body.setSize(size);
    body.setPosition(currPos);
    return body;
}

// Snake(const Snake &sn)
// {
//     this->sz = sn.sz;
//     this->segPos = sn.segPos;
// }
bool collision(const sf::RectangleShape& head, const sf::RectangleShape& body)
{
    return head.getGlobalBounds().intersects(body.getGlobalBounds() );
}

// bool FoodCollision(const sf::RectangleShape& head, const sf::RectangleShape& food)
// {
//     return head.getGlobalBounds().intersects(food.getGlobalBounds() );
// }

void eat(sf::Vector2f prevLocation)
{
    sf::Vector2f newLoc = snakeBody[consumption - 1].getPosition();
    snakeBody.push_back(createBody(sz, newLoc));
    //prevLoc
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

sf::Vector2f setSegPos()
{
    return segPos;
}

void setSegXY(float newX , float newY)
{
    x = newX;
    y = newY;
    segPos.x = x;
    segPos.y = y;
}

// void setSegXY(sf::Vector2f sPos)
// {
//     // x = newX;
//     // y = newY;
//     // segPos.x = x;
//     // segPos.y = y;
//     segPos = sPos;
// }


float getSegXY()
{
    return x && y;
}

void setDir(bool dir) //change to int or float 
//instead of bool make pos absolute
{
    if(left == dir)
    {
        //dir == left;
        dir = traj;
    }
     if(right == dir)
    {
        //dir == right;
        dir = traj;
    }
     if(up == dir)
    {
        //dir == up;
        dir = traj;
    }
     if(down == dir)
    {
        //dir == down;
        dir = traj;
    }
}

bool getDir()
{
    return traj;
}
            //for additional segments multiply delta??
void direction(sf::Event e, float delta)
{

    evt = e;
    if(e.key.code == sf::Keyboard::Left || evt.key.code == sf::Keyboard::A)
    {
        left = true;
        vel.x = -50.0f;
        vel.y = 0.0f;

        velDelay.x = -45.0f;
        velDelay.y = 0.0f;
        //setSegXY(pos.x/2*consumption+1 , pos.y);
       // setSegXY(pos.x+10*consumption+1 , pos.y);
        count +=1;
    }
    if(e.key.code == sf::Keyboard::Right && evt.KeyReleased|| evt.key.code == sf::Keyboard::D)
    {
        right = true;
        vel.x = 50.0f;
        vel.y = 0.0f;

        velDelay.x = 45.0f;
        velDelay.y = 0.0f;
        //setSegXY(pos.x/2*consumption+1 , pos.y);
       // setSegXY(pos.x-10*consumption+1 , pos.y);
       count +=1;
        
    }
    if(e.key.code == sf::Keyboard::Up || evt.key.code == sf::Keyboard::W)
    {
        up = true;
        vel.x = 0.0f;
        vel.y = -50.0f;

        velDelay.x = 0.0f;
        velDelay.y = -45.0f;
        //setSegXY(pos.x , pos.y/2*consumption+1);
       // setSegXY(pos.x , pos.y+10*consumption+1);
       count +=1;
    }
    if(e.key.code == sf::Keyboard::Down || evt.key.code == sf::Keyboard::D)
    {
        down = true;
        vel.x = 0.0f;
        vel.y = 50.0f;

        velDelay.x = 0.0f;
        velDelay.y = 45.0f;
        count +=1;
        //setSegXY(pos.x , pos.y/2*consumption+1);
        //setSegXY(pos.x , pos.y-10*consumption+1);
        
        
    }
    pos += vel * delta;
    prevLocation.push_back(pos);
    rectsize.x = 20;
    rectsize.y = 20;

    setSegXY(prevLocation[count-1].x , prevLocation[count-1].y);
            //currently needs to create new only creating one instance and reusing 
    //snakeBody.push_back(createBody(sz, prevLocation[count-1]));
    snakeBody.resize(consumption+1);
    snakeBody.push_back(createBody(rectsize, prevLocation[consumption]));

    //segPos += velDelay * delta;
    //setSegXY(segPos);
}




void DrawHead(sf::RenderWindow &win)
{
    win.draw(bodySegment);
}

void DrawBody(sf::RenderWindow &win)
{   //for(auto s : )
    for(int snk = 1; snk < snakeBody.size(); snk++)
    {
        win.draw(snakeBody[snk]);
    }
    //r->draw(snakeBody[0]);
}

// void hungry()
// {
//     if()
// }



};





#endif