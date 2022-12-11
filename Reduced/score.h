#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>

class Score
{
    public: 
    int eat;
    sf::Font snake;
    sf::Text title;

    
    void SetTitle()
    {
        snake.loadFromFile("RockSalt-Regular.ttf");
        title.setFont(snake);
        title.setString("Snake");
        title.setCharacterSize(30);
        title.setFillColor(sf::Color::Green);
        title.setOutlineColor(sf::Color::Red);
        title.setOutlineThickness(3);
        title.setPosition(140,5);
    }
    void DrawTitle(sf::RenderWindow &win)
    {
        win.draw(title);
    }



};
#endif