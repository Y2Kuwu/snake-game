#include "getEng.h"
#include "score.h"
#include "snacks.h"

const sf::Time GetEng::TPF = sf::seconds(1.f/60.f);

    GetEng::GetEng()
    {
        
        winSz = sf::Vector2f(400,400);
        win.create(sf::VideoMode(winSz.x , winSz.y), "Snake", sf::Style::Default);
        win.setFramerateLimit(FPS);
      
        

        background();
        score.SetPrompt();
        score.SetScore();
        score.SetTitle();
      
        
       
        dead = false;
        callRand = true;
        
        
        //drawPrompt(countCycle);
        getInit();
        
    }
    void GetEng::background()
    {
    back.setSize(sf::Vector2f(360,360));
    back.setPosition(sf::Vector2f(20,20));
    back.setFillColor(sf::Color::White);
    back.setOutlineColor(sf::Color::Red);
    back.setOutlineThickness(6);

    backOutline.setSize(sf::Vector2f(360,40));
    backOutline.setPosition(sf::Vector2f(20,20));
    backOutline.setFillColor(sf::Color::Red);
    }


     void GetEng::getInit()
    {
        last = sf::Time::Zero;
        speed = 4;
        foodIn = 0;
        newSnk();
        dir = dirPush::UP;
        //pushDir(dirPush::UP);
        dirQue.clear();
        //callRand = false;
        //add snacks here
    }
   
    // void GetEng::drawFood(Snacks a,Snacks b)
    // {
        
    //     std::vector<Snacks> snx;
    //     snx.insert(snx.begin(), a);
    //     snx.insert(snx.begin()+1, b);
        
    //     for(int snk = 0; snk < snx.size(); snk++){
    //     snx[snk].makeSnacks(win);
    //     }
    //     win.display();
    // }
    void GetEng::setSnack()
    {
        
        snackSack.clear();
        
        //snackSack.reserve(2);
        sf::Vector2f collisionBox(20,20);
        int randomPosX1 = (rand() % 340 + 20);
        int randomPosY1 = (rand() % 310 + 60);
        int randomPosX2 = (rand() % 340 + 20);
        int randomPosY2 = (rand() % 310 + 60);
        sf::Vector2f randPos1(randomPosX1, randomPosY1);
        sf::Vector2f randPos2(randomPosX2, randomPosY2);

        //snackSack.emplace_back(sf::Vector2f(randomPosX1, randomPosY1));
        
        
        //impact.emplace_back(randPos1);
        // impact.emplace_back(randPos2);
        snackSack.emplace_back(randPos1);
        snackSack.emplace_back(randPos2);

        // .setBounds(sf::Vector2f(randomPosX1, randomPosY1));
        // .setBounds(sf::Vector2f(randomPosX2, randomPosY2));
        

        //snackSack[0].setBounds(randPos1);
        //snackSack[1].setBounds(randPos2);
        // snackSack[0].getBounds();
        // snackSack[1].getBounds();
        // snackSack[0].upd();
        // snackSack[1].upd();

        // impact[1].setImpact(sf::Vector2f(randomPosX2, randomPosY2));
        
        

        

        //Collision impact1(collisionBox, randPos1);
        //Collision impact2(collisionBox, randPos2);
        //impact.insert(impact.begin(), impact1);
       //impact.insert(impact.begin()+1, impact2);
        // Snacks snack1(6 ,randPos1);
        // Snacks snack2(6 ,randPos1);
        //snack1.SetBounds1(randPos1);
        // snack2.SetBounds2(randPos2);

        // snackSack.insert(snackSack.begin(), snack1);
        // snackSack.insert(snackSack.begin()+1, snack2);
        food1 = sf::FloatRect(randPos1, collisionBox);
        food2 = sf::FloatRect(randPos2, collisionBox);

        callRand = false;
    }


    void GetEng::newSnk()
    {
        snake.clear();
        snake.emplace_back(sf::Vector2f(190,190));
        snake.emplace_back(sf::Vector2f(190,200));
        snake.emplace_back(sf::Vector2f(190,210));
    }
    
   


    // void GetEng::foodLocations(sf::FloatRect snack1, sf::FloatRect snack2)
    // {
    //     food1 = snack1;
    //     food2 = snack2;
    //     //eat();
    // }

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
               foodIn+=1;
               score.EatFood(foodIn);
               //add();
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

    void GetEng::drawPrompt(int cycle)
    {
        prompt.setSize(sf::Vector2f(360,320));
        prompt.setPosition(sf::Vector2f(20,60));
        prompt.setFillColor(sf::Color(255,255,255,128));
        prompt.setOutlineColor(sf::Color::Black);
        prompt.setOutlineThickness(4);
        

        if(cycle % 2 == 0)
        {
            score.promptStart.setFillColor(sf::Color::Red);
            score.promptStart.setOutlineColor(sf::Color::Black);
            
        }
        else
        {
        score.promptStart.setFillColor(sf::Color::Black);
        score.promptStart.setOutlineColor(sf::Color::Red);
       
        }
        
    }

   


     void GetEng::drawSnake()
    {
        win.clear();

        for(auto &snk : snake)
        {
            //win.draw(back);
            //win.draw(backOutline);
            //score.DrawTitle(win);
            //score.DrawScore(win);
            win.draw(snk.getSeg());
            
        }
        for(auto &snx : snackSack)
        {
            win.draw(snx.getSnack());
        }
        // if(start == false)
        // {
        // //win.draw(back);
        // //win.draw(backOutline);
        // win.draw(prompt);
        // win.draw(score.promptStart);
      
        // }
       

        win.display();
    }

void GetEng::checkStart()
{
    sf::Event evt;

 while (win.pollEvent(evt)) {
    // Window closed
    if (evt.type == sf::Event::Closed) {
      win.close();
    }
    if(evt.key.code == sf::Keyboard::Space)
    {
        start = true;
    }
 }
}

void GetEng::slither()
{

    sf::Event evt{};

 while (win.pollEvent(evt)) {
    // Window closed
    if (evt.type == sf::Event::Closed) {
      win.close();
    }


    if(evt.key.code == sf::Keyboard::Left)// || evt.key.code == sf::Keyboard::A)
    {
        //left = true;
        // vel.x = -50.0f;
        // vel.y = 0.0f;

        // currPos.x = -50.0f;
        // currPos.y = 0.0f;
        // snake[0].setPos(sf::Vector2f(currPos.x,currPos.y));
        pushDir(dirPush::LEFT);
    }
    else if(evt.key.code == sf::Keyboard::Right)// || evt.key.code == sf::Keyboard::D)
    {
        //right = true;
        // vel.x = 50.0f;
        // vel.y = 0.0f;

        // currPos.x = 50.0f;
        // currPos.y = 0.0f;
        // snake[0].setPos(sf::Vector2f(currPos.x,currPos.y));
       pushDir(dirPush::RIGHT);
    }
    else if(evt.key.code == sf::Keyboard::Up)// || evt.key.code == sf::Keyboard::W)
    {
        //up = true;
        //  vel.x = 50.0f;
        // vel.y = 0.0f;

        // currPos.x = 50.0f;
        // currPos.y = 0.0f;
        // snake[0].setPos(sf::Vector2f(currPos.x,currPos.y));
        pushDir(dirPush::UP);
    }
    else if(evt.key.code == sf::Keyboard::Down) //|| evt.key.code == sf::Keyboard::S)
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
        sf::Vector2f currPos;
        sf::Vector2f prevPos;
        currPos = snake[0].getPos();
        prevPos = currPos;

        if(!dirQue.empty())
        {
            switch (dir)
            {
                case dirPush::UP:
                //snake[0].setPos(sf::Vector2f(currPos.x,currPos.y+30));
                if (dirQue.front() != dirPush::DOWN) {
                dir = dirQue.front();
                }
          break;
                case dirPush::DOWN:
                //snake[0].setPos(sf::Vector2f(currPos.x,currPos.y-30));
                if (dirQue.front() != dirPush::UP) {
                dir = dirQue.front();
                }
          break;
                case dirPush::LEFT:
                //snake[0].setPos(sf::Vector2f(currPos.x-30,currPos.y));
                if (dirQue.front() != dirPush::RIGHT) {
                dir = dirQue.front();
                }
          break;
                case dirPush::RIGHT:
                //snake[0].setPos(sf::Vector2f(currPos.x+30,currPos.y));
                if (dirQue.front() != dirPush::LEFT) {
                dir = dirQue.front();
                }
          break;


            }
            dirQue.pop_front();
            }
            
                //eat();
                // if(foodIn)
                // {
                //     add();
                // }
        switch (dir)
            {
                case dirPush::UP:
                snake[0].setPos(sf::Vector2f(currPos.x,currPos.y-30));
                
          break;
                case dirPush::DOWN:
                snake[0].setPos(sf::Vector2f(currPos.x,currPos.y+30));
                
          break;
                case dirPush::LEFT:
                snake[0].setPos(sf::Vector2f(currPos.x-30,currPos.y));
                
          break;
                case dirPush::RIGHT:
                snake[0].setPos(sf::Vector2f(currPos.x+30,currPos.y));
          break;
            }
        


        // if(dirPush::RIGHT)
        // {
        //     snake[0].setPos(sf::Vector2f(currPos.x+30,currPos.y));
        // }
        // if(dirPush::LEFT)
        // {
        //     snake[0].setPos(sf::Vector2f(currPos.x-30,currPos.y));
        // }

        // if(dirPush::UP)
        // {
        //     snake[0].setPos(sf::Vector2f(currPos.x,currPos.y+30));
        // }

        // if(dirPush::DOWN)
        // {
        //     snake[0].setPos(sf::Vector2f(currPos.x,currPos.y-30));
        // }
        

        // if(foodIn++)
        // {
        //     add();
        // }
    //add();
        

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
        snk.upd();
    }
        eat();
    
         last = sf::Time::Zero;
    }
    }
    
    // void GetEng::in()
    // {
    //      sf::Clock init;
    //     while(win.isOpen())
    //     {
    //     sf::Time deltaTime = init.restart();

    //     if(start == false)
    //     {
    //     countCycle += 1;
    //     sf::sleep(sf::seconds(.5));
    //     win.clear();
    //     win.draw(back);
    //     win.draw(backOutline);
    //     score.DrawTitle(win);
    //     score.DrawScore(win);
    //     win.draw(prompt);
    //     win.draw(score.promptStart);
    //     win.display();
    //     checkStart();
    //     drawPrompt(countCycle);
    //     }
    //     else if(start == true)
    //     {
    //         runSnake();
    //     }
        
    //     }
   // }


    void GetEng::runSnake()
    {
        sf::Clock init;
        while(win.isOpen())
        {
        sf::Time deltaTime = init.restart();
        if(dead == false)
        {
        slither();
        drawSnake();
        }
        if(callRand == true)
        {
            setSnack();
        }
        // if(start == false)
        // {
        
        // countCycle += 1;
        // sf::sleep(sf::seconds(.5));
        // drawPrompt(countCycle);
        // win.draw(prompt);
        // win.draw(score.promptStart);
        // win.display();
        // checkStart();
        // }
        slither();
        upd();
        drawSnake();
        // if(start == true)
        // {
        // slither();
        // upd();
        // drawSnake();
        // }
      
       
        
        
        //sf::sleep(sf::milliseconds(2)); 

        last += deltaTime;
        
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



