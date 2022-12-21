#ifndef SNAKE_H
#define SNAKE_H
#include<SFML/Graphics.hpp>
#include"snacks.h"
#include<list>

#define BODY 10
class Snake
{
private:

int count = 0;
int speed;

sf::Vector2f pos;

sf::Vector2f segPos;
sf::Vector2f vel;

float x , y;
sf::RectangleShape bodySegment;

std::vector<sf::Vector2f>prevLocation;

std::vector<sf::RectangleShape>snakeBody;


bool left;
bool right;
bool up;
bool down;

bool traj;


int add = 0;

sf::Event evt;

sf::Vector2f sz;



  std::list<sf::Sprite> body;
  std::list<sf::Sprite>::iterator head;
  std::list<sf::Sprite>::iterator tail;


public:
//was 1
int consumption = 0;

Snake() = default;

Snake(sf::Vector2f size, sf::Vector2f location)
{
    bodySegment.setSize(size);
    bodySegment.setFillColor(sf::Color::Green);
    bodySegment.setOutlineColor(sf::Color::Black);
    bodySegment.setOutlineThickness(6);
    bodySegment.setPosition(location);
}


bool collision(const sf::RectangleShape& head, const sf::RectangleShape& body)
{
    return head.getGlobalBounds().intersects(body.getGlobalBounds() );
}




int getLen()
{
    return consumption;
}

void setPos(sf::Vector2f position)
{
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
sf::RectangleShape createNew(sf::RectangleShape r,sf::Vector2f seg);

void setSegXY(float newX , float newY)
{
    x = newX;
    y = newY;
    segPos.x = x;
    segPos.y = y;
}


float getSegXY()
{
    return x && y;
}



// bool getDir()
// {
//     return traj;
// }
            //for additional segments multiply delta??
void direction(sf::Event e, float delta)
{

    evt = e;
    if(e.key.code == sf::Keyboard::Left || evt.key.code == sf::Keyboard::A)
    {
        left = true;
        vel.x = -50.0f;
        vel.y = 0.0f;

       // velDelay.x = -45.0f;
       // velDelay.y = 0.0f;
        //setSegXY(pos.x/2*consumption+1 , pos.y);
       // setSegXY(pos.x+10*consumption+1 , pos.y);
       count +=1;
    }
    if(e.key.code == sf::Keyboard::Right && evt.KeyReleased|| evt.key.code == sf::Keyboard::D)
    {
        right = true;
        vel.x = 50.0f;
        vel.y = 0.0f;

       // velDelay.x = 45.0f;
        //velDelay.y = 0.0f;
        //setSegXY(pos.x/2*consumption+1 , pos.y);
       // setSegXY(pos.x-10*consumption+1 , pos.y);
       count +=1;
        
    }
    if(e.key.code == sf::Keyboard::Up || evt.key.code == sf::Keyboard::W)
    {
        up = true;
        vel.x = 0.0f;
        vel.y = -50.0f;

        // velDelay.x = 0.0f;
        // velDelay.y = -45.0f;
        //setSegXY(pos.x , pos.y/2*consumption+1);
       // setSegXY(pos.x , pos.y+10*consumption+1);
       count +=1;
    }
    if(e.key.code == sf::Keyboard::Down || evt.key.code == sf::Keyboard::D)
    {
        down = true;
        vel.x = 0.0f;
        vel.y = 50.0f;

        // velDelay.x = 0.0f;
        // velDelay.y = 45.0f;
        count +=1;
        //setSegXY(pos.x , pos.y/2*consumption+1);
        //setSegXY(pos.x , pos.y-10*consumption+1);
        
        
    }
    pos += vel * delta;
    prevLocation.push_back(pos);

    setSegXY(prevLocation[count-1].x , prevLocation[count-1].y);
}

// void setLen(int consumed)
// {
//     rectsize.x = 10;
//     rectsize.y = 10;
//     consumption = consumed;
//     bodySegment.setPosition(prevLocation[consumed-1]);
//     bodySegment.setSize(rectsize);
//     bodySegment.setFillColor(sf::Color::Green);
//     bodySegment.setOutlineColor(sf::Color::Black);
//     bodySegment.setOutlineThickness(6);
// }



void DrawHead(sf::RenderWindow &win)
{
    win.draw(bodySegment);
}

void DrawBody(sf::RenderWindow &win)
{   
    for(int snk = 0; snk < snakeBody.size(); snk++)
    {
        bodySegment.setPosition(prevLocation[snk]);
        //std::cout << snakeBody.size();
        //snakeBody[snk].setPosition(setSegPos());
        win.draw(snakeBody[snk]);
    }
    //r->draw(snakeBody[0]);
}

};




#endif




// void setDir(bool dir) //change to int or float 
// //instead of bool make pos absolute
// {
//     if(left == dir)
//     {
//         //dir == left;
//         dir = traj;
//     }
//      if(right == dir)
//     {
//         //dir == right;
//         dir = traj;
//     }
//      if(up == dir)
//     {
//         //dir == up;
//         dir = traj;
//     }
//      if(down == dir)
//     {
//         //dir == down;
//         dir = traj;
//     }
// }











// void createBody(sf::Vector2f size, sf::RectangleShape seg,sf::Vector2f segPos)
// {
//     seg.setSize(size);
//     seg.setFillColor(sf::Color::Green);
//     seg.setOutlineColor(sf::Color::Black);
//     seg.setOutlineThickness(6);
//     seg.setPosition(segPos);
//     snakeBody.insert(snakeBody.begin()+consumption-1, bodySegment);
//     //std::cout << snakeBody.size();
// }