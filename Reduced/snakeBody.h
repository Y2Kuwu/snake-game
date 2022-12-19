#ifndef SNAKE_H
#define SNAKE_H
#include<SFML/Graphics.hpp>
#include"snacks.h"

#define BODY 10
class Snake
{
private:

 // 
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


public:
int consumption = 1;

Snake() = default;

Snake(sf::Vector2f size, sf::Vector2f currPos)
{
    bodySegment.setSize(size);
    bodySegment.setFillColor(sf::Color::Green);
    bodySegment.setOutlineColor(sf::Color::Black);
    bodySegment.setOutlineThickness(6);
    bodySegment.move(currPos);
}


// sf::RectangleShape createBody(sf::Vector2f size , sf::Vector2f currPos)
// {
//     sf::RectangleShape body;
//     body.setSize(size);
//     body.setPosition(currPos);
//     return body;
// }

bool collision(const sf::RectangleShape& head, const sf::RectangleShape& body)
{
    return head.getGlobalBounds().intersects(body.getGlobalBounds() );
}

// void eat(sf::Vector2f prevLocation)
// {
//     sf::Vector2f newLoc = snakeBody[consumption - 1].getPosition();
//     snakeBody.push_back(createBody(sz, newLoc));
// }


void setLen(int consumed)
{
    consumption = consumed;
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
    //snakeBody.resize(consumption+1);

    //snakeBody.push_back(createBody(rectsize, prevLocation[consumption]));
    //snakeBody.push_back(bodySegment);

    //segPos += velDelay * delta;
    //setSegXY(segPos);
}




void DrawHead(sf::RenderWindow &win)
{
    win.draw(bodySegment);
}

void DrawBody(sf::RenderWindow &win)
{   //for(auto s : )
    for(int snk = 0; snk < snakeBody.size(); snk++)
    {
        win.draw(snakeBody[snk]);
    }
    //r->draw(snakeBody[0]);
}



};

class SnakeSegments : private Snake
{
private:


public:
std::vector<sf::RectangleShape>snkbody;
//sf::RectangleShape body;

void DrawSnakeBody(sf::RenderWindow &r)
{
    for(int s = 0; s < consumption; s++)
    {
        std::cout << snkbody.size();
        r.draw(snkbody[s]);
    }
}

sf::RectangleShape getBody( sf::Vector2f pos)
	{
		sf::RectangleShape body;
		body.setSize(sf::Vector2f(BODY,BODY));
		body.setPosition(pos);
		return body;

	}


SnakeSegments() = default;
SnakeSegments(sf::RenderWindow &r)
{
    
    //this->body.setSize(sf::Vector2f(BODY,BODY));
    //this->body.setPosition(previousLoc);
    
   // this->body.setFillColor(sf::Color::Green);
    //this->body.setOutlineColor(sf::Color::Black);
   // this->body.setOutlineThickness(6);
    snkbody.push_back(getBody(setSegPos()));
   
   DrawSnakeBody(r);
}



};




#endif