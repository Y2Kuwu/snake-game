#ifndef GET_H
#define GET_H
#include <SFML/Graphics.hpp>
#include "snakeBody.h"
#include "snacks.h"

namespace start
{
bool impact(const sf::RectangleShape& , const sf::RectangleShape& );
sf::RectangleShape getSegment(sf::Vector2f dirLoc);
sf::Event evt;
float deltaTime;
int foodIn;
sf::Vector2f headLocation;
sf::FloatRect headBox;




class Get
{
    public:
    Get(sf::RenderWindow *window);
    void init();

    private:
    void loop(); //game loop
    void set(); // set static
    void dead(); //check alive
    void load();
    void delta(float d); // get time
    

    Snake snk;
    Snacks snax;
    sf::RenderWindow *win;
};





}

#endif