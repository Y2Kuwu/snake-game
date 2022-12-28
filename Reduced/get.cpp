#include "get.h"

namespace start
{
    Get::Get(sf::RenderWindow *window) : snk(window)
    {
        win = window;
    }

    void Get::init()
    {
        load();
        loop();
    }

    void Get::loop()
    {

    }

    void Get::set()
    {
        win->clear();
        snk.drawSnk();
    }



    sf::RectangleShape getSegment(sf::Vector2f pos)
{
		sf::RectangleShape seg;
		seg.setSize(sf::Vector2f(10,10));
		seg.setPosition(pos);
		seg.setFillColor(sf::Color::Green);
        seg.setOutlineColor(sf::Color::Black);
        seg.setOutlineThickness(6);
		return seg;
}
}