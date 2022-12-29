#include "get.h"

namespace start
{
   

    // void start::Give::startGame(sf::RenderWindow *window)
    // {
    //     win = window;
    // }

    Get::Get(sf::RenderWindow *window) : snk(window)
    {
        win = window;
       
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

    // void Get::delta(float del)
    // {
    //     deltaTime = del;
    // }

    void Get::init()
    {
        load();
        loop();
    }


    void Get::loop()
    {
        bool starter = true;
        while(starter)
        {
            set();
            snk.dir(evt, deltaTime);
        }

        if(snk.isDead())
        {
            starter = false;
        }
        

    }

    void Get::load()
    {

    }

    void Get::set()
    {
        win->clear();
        snk.drawSnk();
    }

    bool impact(const sf::RectangleShape& head, const sf::RectangleShape& body)
    {
    return head.getGlobalBounds().intersects(body.getGlobalBounds() );
    }



}