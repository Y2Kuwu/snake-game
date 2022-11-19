#ifndef SNAKEBODY_H
#define SNAKEBODY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class snakeBody : public ::sf::Drawable
{
    public: 
    snakeBody(); //default
    //
    virtual~snakeBody(); // making virutal to pass
    void move();
    void addLength();
    void ouroboros();
    virtual void snakePaint(sf::RenderTarget& snkTarget, sf::RenderStates snkState) const; //virtual passed //render target address // draw or render to the target
    sf::RectangleShape deadSnake;
    sf::RenderWindow* win; //get previous pos and replace
    
    food* hungerPtr;

    //define elsewhere under snakeBody   
    private:
    int totLen;
    sf::RectangleShape snkskin; //replace prev
    sf::Time time;
    
    std::vector<sf::RectangleShape>::iterator tail;
    float posX , posY;
    float x , y;
    sf::RectangleShape* curr;
    sf::RectangleShape* prev;
    
};

class food : public ::sf::Drawable
{
    public:
    food();
    //
    virtual~food();
    sf::CircleShape weNeedFood;
    virtual void foodPaint(sf::RenderTarget& snkTarget, sf::RenderStates snkState) const;
    // //define elsewhere under food
};

#endif