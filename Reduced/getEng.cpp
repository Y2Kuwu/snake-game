#include "getEng.h"
#include "score.h"


    GetEng::GetEng()
    {
        //winSz = sf::Vector2f(400,400);
        //win.create(sf::VideoMode(winSz.x , winSz.y), "Snake");
        //getInit();
        score.SetTitle();
        score.SetScore();
        score.DrawScore(win);
        //score.DrawPrompt(win , countCycle);

    }

     void GetEng::getInit()
    {
        foodIn = 0;
        speed = 2;
        newSnk();
        //add snacks

    }
   

    void GetEng::newSnk()
    {
        snake.clear();
        snake.emplace_back(sf::Vector2f(190,190));
        snake.emplace_back(sf::Vector2f(200,190));
        snake.emplace_back(sf::Vector2f(210,190));
    }
    

    void GetEng::foodLocations(sf::FloatRect snack1, sf::FloatRect snack2)
    {
        food1 = snack1;
        food2 = snack2;
    }

    void GetEng::add() 
    {
    sf::Vector2f newLoc = snake[snake.size() - 1].getPos();
    snake.emplace_back(newLoc);
    }

    void GetEng::eat()
    {
        for(auto &snk : snake)
        {
            if(snk.getSeg().getGlobalBounds().intersects(food1) ||
               snk.getSeg().getGlobalBounds().intersects(food2))
               foodIn+=1;
               score.EatFood(foodIn);
        }
    }


    // void GetEng::newDir()
    // {   
        
    // }


     void GetEng::drawSnake()
    {
        for(auto &snk : snake)
        {
            win.draw(snk.getSeg());
        }
    }


    void GetEng::slither(sf::Event evt , float delta)
{
    //e = evt;
    if(evt.key.code == sf::Keyboard::Left || evt.key.code == sf::Keyboard::A)
    {
        //left = true;
        vel.x = -50.0f;
        vel.y = 0.0f;
    }
    if(evt.key.code == sf::Keyboard::Right || evt.key.code == sf::Keyboard::D)
    {
        //right = true;
        vel.x = 50.0f;
        vel.y = 0.0f;
    }
    if(evt.key.code == sf::Keyboard::Up || evt.key.code == sf::Keyboard::W)
    {
        //up = true;
        vel.x = 0.0f;
        vel.y = -50.0f;
    }
    if(evt.key.code == sf::Keyboard::Down || evt.key.code == sf::Keyboard::D)
    {
        //down = true;
        vel.x = 0.0f;
        vel.y = 50.0f;
    }
    pos += vel * delta;
    snake[0].setPos(pos);
    prevPos = pos;

    for(int snk = 1; snk < snake.size(); snk++)
    {
        pos = snake[snk].getPos();
        snake[snk].setPos(prevPos);
        prevPos = pos;
        //snake[snk].slither();
    }
    if(foodIn += snake.size())
    {
        add();
    }
    
    drawSnake();

}


   

    //     sf::RectangleShape getSegment(sf::Vector2f pos)
    // {
	// 	sf::RectangleShape seg;
	// 	seg.setSize(sf::Vector2f(10,10));
	// 	seg.setPosition(pos);
	// 	seg.setFillColor(sf::Color::Green);
    //     seg.setOutlineColor(sf::Color::Black);
    //     seg.setOutlineThickness(6);
	// 	return seg;
    // }

//     void Get::delta(float del)
//     {
//         deltaTime = del;
//     }

  
    

//     void Get::loop()
//     {
//         bool starter = true;
//         while(starter)
//         {
//             set();
//             Snake::dir(evt, deltaTime);
//         }

//         if(Snake::isDead())
//         {
//             starter = false;
//         }
        

//     }
//   void Get::ini()
//     {
//         //load();
//         loop();
//     }
//     // void Get::load()
//     // {

//     // }

//     void Get::set()
//     {
//         win->clear();
//         Snake::drawSnk();
//     }

//     bool impact(const sf::RectangleShape& head, const sf::RectangleShape& body)
//     {
//     return head.getGlobalBounds().intersects(body.getGlobalBounds() );
//     }


