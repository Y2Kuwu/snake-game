#ifndef SNAKE_H
#define SNAKE_H
#include<SFML/Graphics.hpp>
#include<list>

class Snake
{
private:
sf::RectangleShape bodySegment;
sf::Vector2f pos;
int siz;

public:
explicit Snake(sf::Vector2f startPos);
sf::Vector2f getPos();
void setPos(sf::Vector2f newPos);
void setColor(int sz);
void upd();
sf::RectangleShape getSeg();


};
#endif


