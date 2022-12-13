
#include "snakeBody.h"
#include "snacks.h"
#include "score.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>   
#include <iostream>

int main()
{

bool start = false;
bool keyPress = false;

int cycle = 0;
//Snacks snack;
sf::Clock init;


sf::Time flashElap = sf::seconds(1.0f);
Score score;
Snake charmer;
Collision impact;

sf::Vector2f segment(10,10);
sf::Vector2f snakeStart(190,190);

sf::RectangleShape bg;
bg.setSize(sf::Vector2f(360,360));
bg.setPosition(sf::Vector2f(20,20));
bg.setFillColor(sf::Color::White);
bg.setOutlineColor(sf::Color::Red);
bg.setOutlineThickness(6);

sf::RectangleShape bgBorder;
bgBorder.setSize(sf::Vector2f(360,40));
bgBorder.setPosition(sf::Vector2f(20,20));
bgBorder.setFillColor(sf::Color::Red);


sf::RectangleShape block;
block.setSize(sf::Vector2f(360,320));
block.setPosition(sf::Vector2f(20,60));
block.setFillColor(sf::Color(255,255,255,128));
block.setOutlineColor(sf::Color::Black);
block.setOutlineThickness(4);


std::vector<Snake>snakeSkin;

std::vector<Snacks>snacks;
std::vector<Snacks>::iterator snx;
std::vector<sf::Vector2f>snackPos;

sf::Vector2f collisionBox(12,12);

//int nutrients = 0;

sf::Vector2f winSz(400,400);

srand(time(NULL));
int randomPosX1 = rand() % 354 + 20;
int randomPosY1 = rand() % 350 + 45;
int randomPosX2 = rand() % 354 + 20;
int randomPosY2 = rand() % 350 + 45;
sf::Vector2f randPos1(randomPosX1, randomPosY1);
sf::Vector2f randPos2(randomPosX2, randomPosY2);

sf::RenderWindow win(sf::VideoMode(winSz.x , winSz.y), "Snake");
//win.setKeyRepeatEnabled(true);

while( win.isOpen() )
	{

    float del = init.restart().asSeconds();

		sf::Event event;
		while( win.pollEvent( event ) )
		{
			// Close window: exit
			if( event.type == sf::Event::Closed )
				win.close();
		}
    win.clear();
    
    if(start == false)
    {
    charmer.setPos(snakeStart);
    }
    Snake snake(segment, charmer.getPos()); 
    
    snakeSkin.push_back(snake);


    win.draw(bg);
    win.draw(bgBorder);
   
   
    score.SetTitle();
    score.DrawTitle(win);

    snake.DrawBody(win);

  //stop pushing location or erase just use getPostion()

    Snacks food1(6 , randPos1);
    //snackPos.push_back(randPos1);
    Collision snack1(collisionBox, randPos1);
    Snacks food2(6, randPos2);
    //snackPos.push_back(randPos2);
    Collision snack2(collisionBox, randPos2);
    //food1.SetBounds(randPos1);
   

    snacks.push_back(food1);
    snacks.push_back(food2);

    // sf::Vector2f frontSnack;
    // sf::Vector2f backSnack;

    // std::cout << snackPos.front().x;
    // std::cout << "here";
    // std::cout << snackPos.back().x;

    //
    score.SetScore();
    score.DrawScore(win);
    score.SetPrompt();
    //snack1.bgTest(win);
    
    // if(event.type == (sf::Event::KeyPressed))
    //{
     // keyPress = true;
      charmer.direction(event, del);
    //}
    //std::cout << snakeSkin.size();
     for(int nutrients = 0; nutrients < snacks.size(); nutrients++)
    {
      snacks[nutrients].makeSnacks(win);
    for(int snek = 0; snek < snakeSkin.size(); snek++)
    {
      //if(snakeSkin[snek].getPos().x)
      if(snake.getPos().x != charmer.getPos().x || snake.getPos().y != charmer.getPos().y)
      {
        //std::cout << charmer.getPos().x;
        //std::cout << snake.getPos().x;
        snakeSkin.erase(snakeSkin.begin());
      }
      // if(charmer.getPos() == snacks[nutrients].getGlobalBounds())
      // {
      //   std::cout << "yum";
      // }
   
      
    // if(randPos1.x == snake.getPos().x && randPos1.y == snake.getPos().y || randPos2.x == snake.getPos().x && randPos2.y == snake.getPos().y)
    // {
    //     std::cout << "food";
    // }
    }
    
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      start = true;
    }
    if(start == false)//.asSeconds() - flash.asSeconds() >= flashElap.asSeconds() && start == false)
    {
      
      sf::sleep(sf::seconds(.5));
      win.draw(block);
      score.DrawPrompt(win, cycle);
      
      cycle+=1;
    }
    
   

    win.display();
    }
    return EXIT_SUCCESS;
}





//  for(int pos = 0; pos < snackPos.size(); pos++)
//     {

   
//     }

//  if(snackPos[pos].x == snakeSkin[snek].getPos().x || (snackPos[pos].y == snakeSkin[snek].getPos().y))//snake head location == snacks[nutrients].getlocation()
//     {
//       snacks.erase(snacks.begin());
//       std::cout << "yum";
//     } 