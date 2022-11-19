#ifndef FOOD_H
#define FOOD_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

class food : public ::sf::Drawable
{
    public:
    food();
    //
    virtual ~food() {};
    
    sf::CircleShape weNeedFood;
    virtual void draw(sf::RenderTarget& snkTarget, sf::RenderStates snkState) const;
    // //define elsewhere under food
    private:
};

#endif