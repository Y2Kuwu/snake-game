
#include "snakeBody.h"
#include "snacks.h"
#include "score.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>   
#include <iostream>

int main()
{
//Snacks snack;
Score score;

sf::Vector2f segment(20,20);
sf::RectangleShape bg;
bg.setSize(sf::Vector2f(360,360));
bg.setPosition(sf::Vector2f(20,20));
bg.setFillColor(sf::Color::White);
bg.setOutlineColor(sf::Color::Red);
bg.setOutlineThickness(6);

std::vector<Snake>snakeSkin;

std::vector<Snacks>snacks;
std::vector<Snacks>::iterator snx;
std::vector<sf::Vector2f>snackPos;

//int nutrients = 0;

sf::Vector2f winSz(400,400);

srand(time(NULL));
int randomPosX1 = rand() % 360 + 20;
int randomPosY1 = rand() % 360 + 20;
int randomPosX2 = rand() % 360 + 20;
int randomPosY2 = rand() % 360 + 20;
sf::Vector2f randPos1(randomPosX1, randomPosY1);
sf::Vector2f randPos2(randomPosX2, randomPosY2);

sf::RenderWindow win(sf::VideoMode(winSz.x , winSz.y), "Snake");

while( win.isOpen() )
	{
		// Process events
		sf::Event event;
		while( win.pollEvent( event ) )
		{
			// Close window: exit
			if( event.type == sf::Event::Closed )
				win.close();
		}
    win.clear();

    Snake snake(segment, randPos1); 
    snakeSkin.push_back(snake);
        //static location until time and button input
    win.draw(bg);
    //snack.countSnacks();
   
    score.SetTitle();
    score.DrawTitle(win);

    snake.DrawBody(win);

    Snacks food1(6 , randPos1);
    snackPos.push_back(randPos1);
    Snacks food2(6, randPos2);
    snackPos.push_back(randPos2);
  

    snacks.push_back(food1);
    snacks.push_back(food2);
   
    for(int snek = 0; snek < snakeSkin.size(); snek++)
    {
  
    for(int nutrients = 0; nutrients < snacks.size(); nutrients++)
    {
    snacks[nutrients].makeSnacks(win);
    for(int pos = 0; pos < snackPos.size(); pos++)
    {
    if(snackPos[pos] == snakeSkin[snek].getPos())//snake head location == snacks[nutrients].getlocation()
    {
      snacks.erase(snacks.begin());
    } 
    }
    }
    }

    win.display();
    }
    return EXIT_SUCCESS;
}