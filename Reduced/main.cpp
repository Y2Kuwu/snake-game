
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

sf::RectangleShape bg;
bg.setSize(sf::Vector2f(360,360));
bg.setPosition(sf::Vector2f(20,20));
bg.setFillColor(sf::Color::White);
bg.setOutlineColor(sf::Color::Red);
bg.setOutlineThickness(6);

std::vector<Snacks>snacks;
std::vector<Snacks>::iterator snx;
//int nutrients = 0;

sf::Vector2f winSz(400,400);

srand(time(NULL));
int randomPos = rand() % 360 + 20;

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

   
    
    
    //win.draw(bg);
    //snack.countSnacks();
   
    score.SetTitle();
    score.DrawTitle(win);
    Snacks food(6);
    //food.setSnackPos(randomPos , randomPos);
    

    for(int sz = 0; sz < 3; sz++)
    {
    if(sz < 3)
    {
    food.setSnackPos(randomPos , randomPos);
    snx = snacks.begin();
    snx = snacks.insert (snx , food);
    //snacks.insert(snx, 1 ,food);
    sz++;
    }
    
    //if(snacks.size() == 3)
   // {
    // for(int nutrients = 0; nutrients < snacks.size(); nutrients++)
    // {
    //   for(auto snackz : snacks)
    // {
    //for(snx = snacks.begin(); snx < snacks.end(), snx++){
    //std::cout << snacks.size();
    // snacks[nutrients].setSnackPos(randomPos , randomPos);
    // snacks[nutrients].getSnackPos();
    // snacks[nutrients].makeSnacks(win);
   //snx.makeSnacks(win);

    }
   // }
    
    
    win.display();
    }
    return EXIT_SUCCESS;
}