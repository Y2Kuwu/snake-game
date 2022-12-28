#ifndef START
#define START
#include <SFML/Graphics.hpp>
#include "snakeBody.h"
namespace start
{

}

class Get
{
    public:
    Get(sf::RenderWindow *win);
    void init();

    private:
    void loop();
    void set();
    void dead();
    void load();

    Snake snk;
    sf::RenderWindow *win;
};

#endif