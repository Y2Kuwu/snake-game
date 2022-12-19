#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>

class Score
{
    private: 
    int eat = 0;
    sf::Font snake;
    sf::Font prompt;
    sf::Text title;
    sf::Text promptStart;

    
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

    void SetPrompt()
    {
        prompt.loadFromFile("Inconsolata-Medium.ttf");
        promptStart.setFont(prompt);
        promptStart.setString("Press SPACE to start");
        promptStart.setCharacterSize(20);
        promptStart.setFillColor(sf::Color::Black);
        promptStart.setOutlineColor(sf::Color::Red);
        promptStart.setOutlineThickness(3);
        promptStart.setPosition(100,140);
    }

    void SetScore()
    {
        snake.loadFromFile("RockSalt-Regular.ttf");
        title.setFont(snake);
        title.setString("Consumed: " + std::to_string(eat));
        title.setCharacterSize(12);
        title.setFillColor(sf::Color::White);
        title.setOutlineColor(sf::Color::Black);
        title.setOutlineThickness(4);
        title.setPosition(260,340);
    }


    void EatFood(int digest)
    {
        eat = digest;
    }

    int GetFood()
    {
        return eat;
    }

    void DrawPrompt(sf::RenderWindow &win , int cycle)
    {
        if(cycle % 2 == 0)
        {
            promptStart.setFillColor(sf::Color::Red);
            promptStart.setOutlineColor(sf::Color::Black);
            win.draw(promptStart);
        }
        else
        {
        win.draw(promptStart);
        }
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