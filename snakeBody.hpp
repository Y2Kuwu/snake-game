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
    //define elsewhere under snakeBody   
    private:
    int totLen;
    sf::RectangleShape snkskin;
    sf::Time time;
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