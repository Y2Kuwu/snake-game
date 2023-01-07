#include"snakeBody.h"


Snake::Snake(sf::Vector2f startPos)
{
   bodySegment.setSize(sf::Vector2f(10,10));
   bodySegment.setPosition(startPos);
   bodySegment.setFillColor(sf::Color::Green);
   bodySegment.setOutlineColor(sf::Color::Black);
   bodySegment.setOutlineThickness(6); 
   
   pos = startPos;

   if(siz %2 == 0)
   {
     bodySegment.setFillColor(sf::Color::Red);
   }

}

sf::Vector2f Snake::getPos()

{
    return pos;
}

void Snake::setPos(sf::Vector2f newPos)
{
    pos = newPos;
}

void Snake::setColor(int sz)
{
    siz = sz;
}

sf::RectangleShape Snake::getSeg()
{
    return bodySegment;
}

void Snake::upd()
{
    bodySegment.setPosition(pos);
}
  
