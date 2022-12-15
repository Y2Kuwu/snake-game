
#include "snakeBody.h"
#include "snacks.h"
#include "score.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>   
#include <iostream>



int main()
{
bool callRand = false;;

srand ((unsigned) time(0));


bool start = false;
bool keyPress = false;
bool drawFood;

int cycle = 0;
sf::Clock init;


sf::Time flashElap = sf::seconds(1.0f);
Score score;
Snake charmer;
Collision impact;
Snacks snax;

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
//int nutrients = 0;

sf::Vector2f winSz(400,400);


// int *randomPosX1 = NULL; 
// int *randomPosY1 = NULL; 
// int *randomPosX2 = NULL; 
// int *randomPosY2 = NULL; 
//int *randomPosX2 = new int(rand() % 354 + 20);
//int *randomPosY2 = new int(rand() % 350 + 45);
// randomPosX1 = new int(rand() % 354 + 20);
// randomPosY1 = new int(rand() % 350 + 45);
// randomPosX2 = new int(rand() % 354 + 20);
// randomPosY2 = new int(rand() % 350 + 45);

int randomPosX1 = (rand() % 340 + 20);
int randomPosY1 = (rand() % 310 + 60);
int randomPosX2 = (rand() % 340 + 20);
int randomPosY2 = (rand() % 310 + 60);


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
    //was push back
    snakeSkin.insert(snakeSkin.begin(),snake);


     
     sf::Vector2f randPos1(randomPosX1, randomPosY1);
     sf::Vector2f randPos2(randomPosX2, randomPosY2);
     if(callRand == false)
     {
     randSize.insert(randSize.begin(),randPos1);
     randSize.insert(randSize.begin()+1,randPos2);
     }

     //lump in with above bool?? //erase all at same time??
    Snacks food1(6);
    Snacks food2(6);
    Collision impact1(collisionBox);
    Collision impact2(collisionBox);

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

    //std::cout << impact1.GetImpact1().x;
    //std::cout << snake.getPos().x;

    win.draw(bg);
    win.draw(bgBorder);
   
   
    score.SetTitle();
    score.DrawTitle(win);

    snake.DrawBody(win);


    

    score.SetScore();
    score.DrawScore(win);
    score.SetPrompt();
    charmer.direction(event, del);
    sf::Vector2f snkPos;
    snkPos = charmer.getPos();
    sf::FloatRect snakeRect(snkPos, segment);

    sf::Vector2f boxPos1;
    boxPos1 = randSize.front();
    sf::Vector2f boxPos2;
    boxPos2 = randSize.back();

    sf::FloatRect boxRect2(boxPos2, collisionBox);
    sf::FloatRect boxRect1(boxPos1, collisionBox);
    

        // boxPos1.x = impact1.GetImpact1().x;
        // boxPos1.y = impact1.GetImpact1().y;

        // boxPos2.x = impact1.GetImpact2().x;
        // boxPos2.y = impact1.GetImpact2().y;
      //std::cout << boxPos1.x;
      
    //randSize.front().x, randSize.front().y;
    //randSize.back().x, randSize.back().y;

        // bool intersection1 = snakeRect.contains(randSize.front().x,randSize.front().y);
        // bool inter1 = boxRect1.contains(randSize.front().x,randSize.front().y);
      
        // bool intersection2 = snakeRect.contains(randSize.back().x, randSize.back().y);
        // bool inter2 = boxRect2.contains(randSize.back().x, randSize.back().y);
        // sf::FloatRect phase;
        // bool majorCollision1 = snakeRect.intersects(boxRect1 , phase);
        // bool majorCollision2 = snakeRect.intersects(boxRect2 , phase);


        //bool intersection1 = snakeRect.contains(boxPos1.x, boxPos1.y);
        // bool intersection1 = snakeRect.contains(boxPos1.x-1,boxPos1.y-1);
        // bool inter1 = boxRect1.contains(boxPos1.x, boxPos1.y);
      
        // bool intersection2 = snakeRect.contains(boxPos2.x-1,boxPos2.y-1);
        // bool inter2 = boxRect2.contains(boxPos2.x, boxPos2.y);
        // sf::FloatRect phase;
        // bool majorCollision1 = snakeRect.intersects(boxRect1 , phase);
        // bool majorCollision2 = snakeRect.intersects(boxRect2 , phase);

   //snkPos.x = charmer.getPos().x; 
   //snkPos.y = charmer.getPos().y;
   
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
    
     
 
    
    
    for(int nutrients = 0; nutrients < snacks.size(); nutrients++)
     //for(auto f : snacks)
    {
      //std::cout << charmer.getPos().x;
      snacks[nutrients].makeSnacks(win);
      collide[nutrients].bgTest(win);
      if( snakeRect.intersects(boxRect1) || snakeRect.intersects(boxRect2))
      {
        std::cout << "hit";
      }
    }
    }
  

    
      
    
    //for(int box = 0; box < collide.size(); box++)
    //{
        

        // boxPos.x = collide[box].GetImpact1().x;
       
        

        //std::cout << boxPos1.x;
        //collide[box].bgTest(win);
      //  if(majorCollision1 || majorCollision2)
      //  //if( snakeRect.contains(boxPos1) || snakeRect.contains(boxPos2))
      //  {
      //     std::cout << "collision";
      //     std::cout << phase.left;
      //  }
    //}
      //std::cout << randSize.size();  //inserting reads as two maxed out at a time
      //if(randSize[n].x == charmer.getPos().x && randSize[n].y == charmer.getPos().y)
      //if(randPos1.x  == charmer.getPos().x && randPos1.y == charmer.getPos().y)
 
    //    if(snack1.GetBox().contains(charmer.getPos().x , charmer.getPos().y))
      // if(charmer.getPos() == snacks[nutrients].getGlobalBounds())
    // //    {
    //       std::cout << "1";
         
    //      snacks.erase(snacks.begin());
         
    //    }
    // }
    //    if(snack2.GetBox().contains(charmer.getPos().x , charmer.getPos().y))
    //    {
    //      std::cout << "2";
    //      snacks.erase(snacks.begin()+1);
    //    }
    
    //{
    //   std::cout << "yum";
    
      
     if(randPos1.x == snake.getPos().x && randPos1.y == snake.getPos().y || randPos2.x == snake.getPos().x && randPos2.y == snake.getPos().y)
     {
        std::cout << "food";
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