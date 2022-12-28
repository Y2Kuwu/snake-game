#ifndef SNAKE_H
#define SNAKE_H
#include<SFML/Graphics.hpp>
#include"snacks.h"
#include<list>


class Snake
{
private:


bool stretch;
int consumption; //length
sf::RenderWindow *win;
std::list<sf::Vector2<int>>posList;
sf::Vector2<int>prevDir;
std::vector<sf::RectangleShape>snakeBody;

//bool updateLen
//float speed;


int count = 0;
int speed;

sf::Vector2f pos;
sf::Vector2f segPos;
sf::Vector2f vel;

float x , y;


//std::vector<sf::Vector2f>previous;



bool left;
bool right;
bool up;
bool down;


sf::Event evt;
sf::RectangleShape bodySegment;


//   std::list<sf::RectangleShape> body;
//   std::list<sf::RectangleShape>::iterator head;
//   std::list<sf::RectangleShape>::iterator tail;
public:
//was 1
sf::Vector2f sz;
 //length
sf::Vector2f foodPos;
Snacks s;




Snake() = default;
Snake(sf::RenderWindow *);



void drawSnk(); //draw
void slither(sf::Vector2<int> dir); //move
bool isDead(); //check if game playing
int eat(int food);

// Snake(sf::Vector2f size, sf::Vector2f pos)
// {
//     bodySegment.setSize(size);
//     bodySegment.setFillColor(sf::Color::Green);
//     bodySegment.setOutlineColor(sf::Color::Black);
//     bodySegment.setOutlineThickness(6);
//     bodySegment.setPosition(pos);
//     //snakeBody.push_back(bodySegment);
// }



// bool collision(const sf::RectangleShape& head, const sf::RectangleShape& body)
// {
//     return head.getGlobalBounds().intersects(body.getGlobalBounds() );
// }

// int getLen()
// {
//     return consumption;
// }

// void setPos(sf::Vector2f position)
// {
//     pos = position;
// }

// sf::Vector2f getPos()
// {
//     return pos;
// }

// sf::Vector2f setSegPos()
// {
//     return segPos;
// }


// void setSegXY(float newX , float newY)
// {
//     x = newX;
//     y = newY;
//     segPos.x = x;
//     segPos.y = y;
// }


// float getSegXY()
// {
//     return x && y;
// }

// void direction(sf::Event e, float delta)
// {

//     evt = e;
//     if(e.key.code == sf::Keyboard::Left || evt.key.code == sf::Keyboard::A)
//     {
//         left = true;
//         vel.x = -50.0f;
//         vel.y = 0.0f;

//        // velDelay.x = -45.0f;
//        // velDelay.y = 0.0f;
//         //setSegXY(pos.x/2*consumption+1 , pos.y);
//        // setSegXY(pos.x+10*consumption+1 , pos.y);
//        count +=1;
//     }
//     if(e.key.code == sf::Keyboard::Right && evt.KeyReleased|| evt.key.code == sf::Keyboard::D)
//     {
//         right = true;
//         vel.x = 50.0f;
//         vel.y = 0.0f;

//        // velDelay.x = 45.0f;
//         //velDelay.y = 0.0f;
//         //setSegXY(pos.x/2*consumption+1 , pos.y);
//        // setSegXY(pos.x-10*consumption+1 , pos.y);
//        count +=1;
        
//     }
//     if(e.key.code == sf::Keyboard::Up || evt.key.code == sf::Keyboard::W)
//     {
//         up = true;
//         vel.x = 0.0f;
//         vel.y = -50.0f;

//         // velDelay.x = 0.0f;
//         // velDelay.y = -45.0f;
//         //setSegXY(pos.x , pos.y/2*consumption+1);
//        // setSegXY(pos.x , pos.y+10*consumption+1);
//        count +=1;
//     }
//     if(e.key.code == sf::Keyboard::Down || evt.key.code == sf::Keyboard::D)
//     {
//         down = true;
//         vel.x = 0.0f;
//         vel.y = 50.0f;

//         // velDelay.x = 0.0f;
//         // velDelay.y = 45.0f;
//         count +=1;
//         //setSegXY(pos.x , pos.y/2*consumption+1);
//         //setSegXY(pos.x , pos.y-10*consumption+1);
        
        
//     }
//     pos += vel * delta;
//     prevLocation.push_back(pos);

//     setSegXY(prevLocation[count-1].x , prevLocation[count-1].y);
    
// }




// void DrawHead(sf::RenderWindow &win)
// {
//    win.draw(bodySegment);
// }

// void newBody(sf::Vector2f location, sf::RectangleShape bodySegment, sf::Vector2f size)
// {
//      if(consumption+=1)
//     {
//           bodySegment.setSize(size);
//           bodySegment.setFillColor(sf::Color::Red);
//           bodySegment.setOutlineColor(sf::Color::Black);
//           bodySegment.setOutlineThickness(6);
//          // bodySegment.setPosition(location);
//          // snakeBody.push_back(bodySegment);
//     }
  
// }

// void setNewPos(sf::Vector2f newPos, sf::RectangleShape bodySegment)
// {
// for(auto s : snakeBody)
//     {
//     s.setPosition(newPos);
    
//     }
// }

// void DrawBody(sf::RenderWindow &win)
// {   
   
//     for(auto snk : snakeBody)
//     {
//         //std::cout << snakeBody.size();
//        // std::cout << " gap ";
//        // std::cout << consumption;
//        //snk.setPosition(setSegPos());
//         win.draw(snk);
//     }
//     //r->draw(snakeBody[0]);
// }

// };

};


// #endif

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