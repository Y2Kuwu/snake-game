#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>

class Score
{
    private: 
    int eat = 0;
    sf::Font snake;
    sf::Text title;

    
    public:

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

    void SetScore()
    {
        snake.loadFromFile("RockSalt-Regular.ttf");
        title.setFont(snake);
        title.setString("Consumed: " + std::to_string(eat));
        title.setCharacterSize(10);
        title.setFillColor(sf::Color::Red);
        title.setOutlineColor(sf::Color::Black);
        title.setOutlineThickness(1);
        title.setPosition(200,20);
    }


    void EatFood(int digest)
    {
        eat = digest;
    }

    int GetFood()
    {
        return eat;
    }

    void DrawScore(sf::RenderWindow &win)
    {
        win.draw(title);
    }

    void DrawTitle(sf::RenderWindow &win)
    {
        win.draw(title);
    }



};
#endif