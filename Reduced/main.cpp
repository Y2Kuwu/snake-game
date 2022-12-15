
#include "snakeBody.h"
#include "snacks.h"
#include "score.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>   
#include <iostream>
#include <new>



int main()
{
bool callRand;
bool callFood;

srand (time(0));


bool start = false;
bool keyPress = false;
bool drawFood;

int cycle = 0;
sf::Clock init;


sf::Time flashElap = sf::seconds(1.0f);
Score score;
Snake charmer;
Collision impact;
// Snacks* snack1 = new Snacks;
// Snacks* snack2 = new Snacks;


sf::Vector2f segment(10,10);
sf::Vector2f segRect(10,10);
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

std::vector<Collision>collide;

std::vector<sf::Vector2f>randSize;

sf::Vector2f collisionBox(15,15);

sf::Vector2f winSz(400,400);


int randomPosX1 = (rand() % 340 + 20);
int randomPosY1 = (rand() % 310 + 60);
int randomPosX2 = (rand() % 340 + 20);
int randomPosY2 = (rand() % 310 + 60);
 //sf::Vector2f randPos1(randomPosX1, randomPosY1);
 //sf::Vector2f randPos2(randomPosX2, randomPosY2);



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
    callRand = false;
    }
    Snake snake(segment, charmer.getPos()); 
    //was push back
    snakeSkin.insert(snakeSkin.begin(),snake);
    sf::Vector2f randPos1;
    sf::Vector2f randPos2;

    if(callRand == true)
{
   randomPosX1 = 0;
   randomPosX2 = 0;
   randomPosY1 = 0;
   randomPosY2 = 0;
   std::cout << "reset";
randomPosX1 = (rand() % 340 + 20);
randomPosY1 = (rand() % 310 + 60);
randomPosX2 = (rand() % 340 + 20);
randomPosY2 = (rand() % 310 + 60);
callRand = false;
}
    
    win.draw(bg);
    win.draw(bgBorder);
   
    score.SetTitle();
    score.DrawTitle(win);

    snake.DrawBody(win);

    if(callRand == false)
     {
    sf::Vector2f randPos1(randomPosX1, randomPosY1);
    sf::Vector2f randPos2(randomPosX2, randomPosY2);

    Snacks snack1;
    Snacks snack2;
    Snacks food1; //= new Snacks(6);
    Snacks food2; //= new Snacks(6);
    Collision impact1(collisionBox);
    Collision impact2(collisionBox);


    randSize.insert(randSize.begin(),randPos1);
    randSize.insert(randSize.begin()+1,randPos2);


    food1.SetBounds1(randSize.front());
    food1.SetPos1();

    impact1.SetImpactBounds1(randSize.front());
    impact1.SetImpact1();

    food2.SetBounds2(randSize.back());
    food2.SetPos2();

    impact2.SetImpactBounds2(randSize.back());
    impact2.SetImpact2();

    snacks.insert(snacks.begin(), food1);
    snacks.insert(snacks.begin()+1, food2);

    collide.insert(collide.begin(),impact1);
    collide.insert(collide.begin()+1,impact2);
    }
    


    score.SetScore();
    score.DrawScore(win);
    score.SetPrompt();
    charmer.direction(event, del);


    //collision rects
    sf::Vector2f snkPos;
    snkPos = charmer.getPos();
    sf::FloatRect snakeRect(snkPos, segment);

    sf::Vector2f boxPos1;
    boxPos1 = randSize.front();
    sf::Vector2f boxPos2;
    boxPos2 = randSize.back();

    sf::FloatRect boxRect2(boxPos2, collisionBox);
    sf::FloatRect boxRect1(boxPos1, collisionBox);
    //


    
    for(int snek = 0; snek < snakeSkin.size(); snek++)
    {
         // if(charmer.getPos().x == randSize.front().x || charmer.getPos().y == randSize.front().y)
      
      if(snake.getPos().x != charmer.getPos().x || snake.getPos().y != charmer.getPos().y)
      {
       // std::cout << charmer.getPos().x;
       // std::cout << "______";
        //charmer.getPos();
       
        //std::cout << snkPos.x;
        //snakeRect(snakeSkin[snek].getPos().x, snakeSkin[snek].getPos().y, segment.x, segment.y);
        snakeSkin.erase(snakeSkin.begin());
      }
    
     
 
    
    //keep simple
    for(int nutrients = 0; nutrients < snacks.size(); nutrients++)
    {
      snacks[nutrients].makeSnacks(win);
      collide[nutrients].bgTest(win);
      if( snakeRect.intersects(boxRect1) || snakeRect.intersects(boxRect2))
      {
        std::cout << "hit";
      

        collide.clear();
        snacks.clear();
        randSize.clear();
        randPos1.x = 0;
        randPos2.x = 0; 
        randPos1.y= 0;
        randPos2.y = 0; 

    //sf::Vector2f randPos1(randomPosX1, randomPosY1);
    //sf::Vector2f randPos2(randomPosX2, randomPosY2);

    Snacks snack1;
    Snacks snack2;
    Snacks food1; //= new Snacks(6);
    Snacks food2; //= new Snacks(6);
    Collision impact1(collisionBox);
    Collision impact2(collisionBox);



        
     callRand = true;

    

     //callFood = true;
     
      }




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
