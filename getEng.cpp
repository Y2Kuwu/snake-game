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
        speed = 2;
        foodIn = 0;
        newSnk();
        setSnack();
        dir = dirPush::UP;
        dirQue.clear();
    }
    void GetEng::setSnack()
    {
        
        snackSack.clear();
        //snackSack.reserve(2);
        sf::Vector2f collisionBox(15,15);
        int randomPosX1 = (rand() % 340 + 20);
        int randomPosY1 = (rand() % 310 + 60);
        int randomPosX2 = (rand() % 340 + 20);
        int randomPosY2 = (rand() % 310 + 60);
        sf::Vector2f randPos1(randomPosX1, randomPosY1);
        sf::Vector2f randPos2(randomPosX2, randomPosY2);

        snackSack.emplace_back(randPos1);
        snackSack.emplace_back(randPos2);

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
        for(auto &snk : snake)
        {
            snk.setColor(snake.size());
        }
    }
    
    void GetEng::add() 
    {
    sf::Vector2f newLoc = snake[snake.size() - 1].getPos();
    snake.emplace_back(newLoc);

    setSnack();

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
               score.SetScore();
               add();
               snk.setColor(snake.size()-1);
               //score.title.setFillColor(sf::Color::Black);
               //score.title.setOutlineColor(sf::Color::White);
               //flash = true; // add flash seq for food
        
               if(foodIn %2 == 0 && foodIn >= 4)
               {
                speed = foodIn/2;
               }
               }
        }
    }

    void GetEng::death()
    {
        for(int s = 1; s < snake.size(); s++)
        {
            headBox = snake[0].getSeg().getGlobalBounds();
            bodyBox = snake[s].getSeg().getGlobalBounds();

        if(headBox.intersects(bodyBox) )
        {
            dead = true;
            score.SetDead();
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
        
        if(dead == false)
        {
        win.draw(back);
        win.draw(backOutline);
        }

        for(auto &snk : snake)
        {
            win.draw(snk.getSeg());
        }
        for(auto &snx : snackSack)
        {
            win.draw(snx.getSnack());
        }
        
        win.draw(score.score);
        win.draw(score.title);

        win.display();
       
        
    }

void GetEng::checkStart()
{
    sf::Event evt;

 while (win.pollEvent(evt)) {
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

    if (evt.type == sf::Event::Closed) {
      win.close();
    }

    if(evt.key.code == sf::Keyboard::Left || evt.key.code == sf::Keyboard::A)
    {
        pushDir(dirPush::LEFT);
    }
    else if(evt.key.code == sf::Keyboard::Right || evt.key.code == sf::Keyboard::D)
    {
       pushDir(dirPush::RIGHT);
    }
    else if(evt.key.code == sf::Keyboard::Up || evt.key.code == sf::Keyboard::W)
    {
        pushDir(dirPush::UP);
    }
    else if(evt.key.code == sf::Keyboard::Down || evt.key.code == sf::Keyboard::S)
    {
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

        switch (dir)
            {
                case dirPush::UP:
                snake[0].setPos(sf::Vector2f(currPos.x,currPos.y-20));
                
          break;
                case dirPush::DOWN:
                snake[0].setPos(sf::Vector2f(currPos.x,currPos.y+20));
                
          break;
                case dirPush::LEFT:
                snake[0].setPos(sf::Vector2f(currPos.x-20,currPos.y));
                
          break;
                case dirPush::RIGHT:
                snake[0].setPos(sf::Vector2f(currPos.x+20,currPos.y));
          break;
            }
        
        

        for(int snk = 1; snk < snake.size(); snk++)
    {
        currPos = snake[snk].getPos();
        snake[snk].setPos(prevPos);
        prevPos = currPos;
    }
        for(auto & snk : snake)
    {
        snk.upd();
    }
    if(snake.size() >= 4)
    {
        death();
    }
        eat();
        last = sf::Time::Zero;
    }
    }
    
    void GetEng::in()
    {
         sf::Clock init;
        while(win.isOpen())
        {
        sf::Time deltaTime = init.restart();
        
        if(start == false)
        {
        countCycle += 1;
        sf::sleep(sf::seconds(.5));
        win.clear();
        win.draw(back);
        win.draw(backOutline);
        win.draw(prompt);
        win.draw(score.promptStart);
        win.display();
        checkStart();
        drawPrompt(countCycle);
        }
        else if(start == true)
        {
            runSnake();
        }
        
        }
   }


    void GetEng::runSnake()
    {
        sf::Clock init;
        while(win.isOpen())
        {
        sf::Time deltaTime = init.restart();
        sf::Time wait = sf::seconds(.4);
        sf::Time elap;

        if(dead == false)
        {
        slither();
        drawSnake();
        upd();
        }
        if(callRand == true)
        {
            setSnack();
        }
        
         if(dead == true)
        {
            win.clear();
            win.draw(back);
            win.draw(score.promptEnd);
            win.display();
        }
        // if(flash == true)
        // {///wait
        //     //last -= deltaTime + wait;
        //     //score.SetTitle();
        // }
        
        //sf::sleep(sf::milliseconds(2)); 

        last += deltaTime;
        }
        
        
    }




