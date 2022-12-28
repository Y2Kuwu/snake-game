#ifndef GET_H
#define GET_H
#include <SFML/Graphics.hpp>
#include "snakeBody.h"


namespace start
{
bool impact(const sf::RectangleShape& , const sf::RectangleShape& );
sf::RectangleShape getSegment(sf::Vector2f dirLoc);
sf::Event evt;

class Get
{
    public:
    Get(sf::RenderWindow *window);
    void init();

    private:
    void loop();
    void set();
    void dead();
    void load();
    

    Snake snk;
    sf::RenderWindow *win;
};
}

#endif