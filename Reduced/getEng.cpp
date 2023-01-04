#include "getEng.h"
#include "score.h"

const sf::Time GetEng::TPF = sf::seconds(1.f/60.f);

    GetEng::GetEng()
    {
        
        winSz = sf::Vector2f(400,400);
        win.create(sf::VideoMode(winSz.x , winSz.y), "Snake", sf::Style::Default);
        win.setFramerateLimit(FPS);
        //getInit();
        //getInit();
        foodIn = 0;
        score.SetPrompt();
        score.SetTitle();
        score.SetScore();
        score.DrawTitle(win);
        score.DrawScore(win);
       // drawPrompt(countCycle);
        dirQue.clear();
        dead = false;
        getInit();
        //newSnk();
        //score.DrawPrompt(win , countCycle);
        
    }

     void GetEng::getInit()
    {
        foodIn = 0;
        last = sf::Time::Zero;
        //speed = 2;
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
        //eat();
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
               {
               foodIn++;
               score.EatFood(foodIn);
               }
          
            
        }
    }

    void GetEng::death()
    {
        for(auto &snk : snake)
        {
          if(snake[0].getSeg().getGlobalBounds().intersects(snk.getSeg().getGlobalBounds()))
            {
                dead = true;
                score.DrawDead(win);
                //run end cycle
            }
        
        else
        {
            dead = false;
        }
    }
    }

    // void GetEng::drawPrompt(int cycle)
    // {
    //      if(cycle % 2 == 0)
    //     {
    //         score.promptStart.setFillColor(sf::Color::Red);
    //         score.promptStart.setOutlineColor(sf::Color::Black);
    //         win.draw(prompt);
    //         win.draw(score.promptStart);
    //     }
    //     else
    //     {
    //     win.draw(score.promptStart);
    //     }
    //     win.display();
    // }


     void GetEng::drawSnake()
    {

       
        win.clear();
        for(auto &snk : snake)
        {
            win.draw(snk.getSeg());
        }
        win.display();
    }







void GetEng::slither()
{

    sf::Event evt;

 while (win.pollEvent(evt)) {
    // Window closed
    if (evt.type == sf::Event::Closed) {
      win.close();
    }

    if(evt.key.code == sf::Keyboard::Left || evt.key.code == sf::Keyboard::A)
    {
        //left = true;
        // vel.x = -50.0f;
        // vel.y = 0.0f;

        // currPos.x = -50.0f;
        // currPos.y = 0.0f;
        // snake[0].setPos(sf::Vector2f(currPos.x,currPos.y));
        pushDir(dirPush::LEFT);
    }
    if(evt.key.code == sf::Keyboard::Right || evt.key.code == sf::Keyboard::D)
    {
        //right = true;
        // vel.x = 50.0f;
        // vel.y = 0.0f;

        // currPos.x = 50.0f;
        // currPos.y = 0.0f;
        // snake[0].setPos(sf::Vector2f(currPos.x,currPos.y));
       pushDir(dirPush::RIGHT);
    }
    if(evt.key.code == sf::Keyboard::Up || evt.key.code == sf::Keyboard::W)
    {
        //up = true;
        //  vel.x = 50.0f;
        // vel.y = 0.0f;

        // currPos.x = 50.0f;
        // currPos.y = 0.0f;
        // snake[0].setPos(sf::Vector2f(currPos.x,currPos.y));
        pushDir(dirPush::UP);
    }
    if(evt.key.code == sf::Keyboard::Down || evt.key.code == sf::Keyboard::S)
    {
        //down = true;
        // vel.x = 0.0f;
        // vel.y = 50.0f;

        // currPos.x = 0.0f;
        // currPos.y = 50.0f;
        // snake[0].setPos(sf::Vector2f(currPos.x,currPos.y));
        pushDir(dirPush::DOWN);
    }

 

   
    
    }
    
   
    }



    void GetEng::pushDir(int dir)
    {
        if(dirQue.empty())
        {
            dirQue.emplace_back(dir);
        }
        else if (dirQue.back() != dir) 
        {
        dirQue.emplace_back(dir);
        }
    }


    void GetEng::upd()
    {
         if(last.asSeconds() >= sf::seconds(1.f / float(speed)).asSeconds())
    {   
        currPos = snake[0].getPos();
        prevPos = currPos;

        if(!dirQue.empty())
        {
            switch (dir)
            {
                case dirPush::UP:
                if (dirQue.front() != dirPush::DOWN) {
                dir = dirQue.front();
                snake[0].setPos(sf::Vector2f(currPos.x,currPos.y+30));
                }
          break;

             switch (dir)
            {
                case dirPush::DOWN:
                if (dirQue.front() != dirPush::UP) {
                dir = dirQue.front();
                snake[0].setPos(sf::Vector2f(currPos.x,currPos.y-30));
                }
          break;

             switch (dir)
            {
                case dirPush::LEFT:
                if (dirQue.front() != dirPush::RIGHT) {
                dir = dirQue.front();
                snake[0].setPos(sf::Vector2f(currPos.x-30,currPos.y));
                }
          break;

             switch (dir)
            {
                case dirPush::RIGHT:
                if (dirQue.front() != dirPush::LEFT) {
                dir = dirQue.front();
                 snake[0].setPos(sf::Vector2f(currPos.x+30,currPos.y));
                }
          break;

            }
            dirQue.pop_front();
            }
        }
        if(foodIn++)
        {
            add();
        }


        for(int snk = 1; snk < snake.size(); snk++)
    {
        //vel = snake[snk].getPos();
        currPos = snake[snk].getPos();
        snake[snk].setPos(prevPos);
        prevPos = currPos;
        //snake[snk].slither();
    }
        for(auto & snk : snake)
    {
        snk.slither();
    }
        death();
    }
         last = sf::Time::Zero;
    }
    }
    }



    void GetEng::runSnake()
    {
        sf::Clock init;
        
        while(win.isOpen())
        {
        sf::Time deltaTime = init.restart();
        if(dead == false)
        {
        drawSnake();
         
        //continue;
        }
        //sf::sleep(sf::milliseconds(2)); 

        last += deltaTime;
        
        slither();
        upd();
        drawSnake();

        }
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



