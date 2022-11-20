#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "snakeBody.h"
#include "food.h"
    
int main(){
   
    sf::Time elapsed;
    sf::Clock clock;
    
    // const float movementSpeed = 2.f;
    // float up,down,left,right = 0;
    

    sf::RenderWindow app(sf::VideoMode(700, 700), "Snake");
    sf::RectangleShape rec1;
    sf::RectangleShape rec2;
    sf::RectangleShape rec3;
    //static
    snakeBody snakeBody;
    food food;

    snakeBody.win = &app;
    snakeBody.hungerPtr = &food;
    //Game snk(rec3);

    

    //borders
    sf::RectangleShape n, e, s, w;
    w.setSize(sf::Vector2f(5,650));
    w.setPosition(25, 25);
    e.setSize(sf::Vector2f(5, 650));
    e.setPosition(670, 25);
    n.setSize(sf::Vector2f(650, 5));
    n.setPosition(25, 25);
    s.setSize(sf::Vector2f(650, 5));
    s.setPosition(25, 670);
    //
    //border boundaries for collision
    sf::FloatRect boundsN = n.getGlobalBounds();
    sf::FloatRect boundsE = e.getGlobalBounds();
    sf::FloatRect boundsS = s.getGlobalBounds();
    sf::FloatRect boundsW = w.getGlobalBounds();
    n.setFillColor(sf::Color::Red);
    e.setFillColor(sf::Color::Red);
    s.setFillColor(sf::Color::Red);
    w.setFillColor(sf::Color::Red);
    //

    //static 
    rec1.setFillColor(sf::Color::Cyan);
    rec1.setSize(sf::Vector2f(670, 670));
    rec1.setPosition(15, 15);

    rec2.setFillColor(sf::Color::White);
    rec2.setSize(sf::Vector2f(650, 650));
    rec2.setOutlineColor(sf::Color::Black);
    rec2.setOutlineThickness(4);
    rec2.setPosition(25, 25);
    

    rec3.setSize(sf::Vector2f(20,20));
    rec3.setOrigin(-340,-340);
    rec3.setFillColor(sf::Color::Red);
    
    //player collision box
    sf::FloatRect inner = rec3.getGlobalBounds();
    //

    //player position
    sf::Vector2f SnakeHead = rec3.getPosition();
    sf::Vector2f snakePath;
    //

    std::vector <sf::RectangleShape> myRecs;
    myRecs.insert(myRecs.end(),{rec1,rec2,rec3});

    std::vector <sf::RectangleShape>::iterator recDis;

    int pressCount = 0;

    //title box
    sf::Font bars;
    bars.loadFromFile("LibreBarcode39Text-Regular.ttf");
    sf::Text text("SNAKE", bars, 60);
    text.setColor(sf::Color::Black);
    text.setPosition(sf::Vector2f(275,20));
    text.setOutlineColor(sf::Color::Red);
    text.setOutlineThickness(2);
    
    //
    //text for visual testing
    
    // std::string testX;
    // testX = snakeHead.x;
    // std::string testY;
    // testY = snakeHead.y;

    ///sf::Text testText(std::to_string(snakeHead.x), sf::Text::, 20);

    // sf::Text testText;
    // sf::Text testText1;
    // sf::Font def;
    // def.loadFromFile("MG.ttf");
    // testText.setFont(def);
    // testText.setCharacterSize(20);
    // testText.setStyle(sf::Text::Regular);
    
    // testText.setPosition(sf::Vector2f(275,120));
    // testText.setColor(sf::Color::Black);

    // testText1.setFont(def);
    // testText1.setCharacterSize(20);
    // testText1.setStyle(sf::Text::Regular);
    
    // testText1.setPosition(sf::Vector2f(275,140));
    // testText1.setColor(sf::Color::Black);
   

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();
              if (event.type == sf::Event::Resized)
    {
             sf::FloatRect visibleArea(-600, -200, event.size.width, event.size.height);
             app.setView(sf::View(visibleArea));
    }
            //added event trigger
           // snk.RestartClock();
        //  for (recDis = myRecs.begin(); recDis != myRecs.end(); ++recDis) {  //will need to be called for redraw
        //     window.draw(*recDis);  
        //     std::cout << "fart";
        //  }
           // if(event.type == sf::Event::KeyPressed){
            //snk.KeyIsPressed(rec3, event);
            // window.draw(rec1);
            // window.draw(rec2);
            // window.draw(rec3);
            // window.draw(text);
            // window.draw(testText);
            // window.draw(testText1);

            snakeBody.move();
            snakeBody.ouroboros();
            app.clear();
            app.draw(snakeBody);
            //app.draw(food);
            
            app.display();

            // if (event.type == sf::Event::KeyPressed)
            // {
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            // {
            //   sf::Clock clock;
            //   snakePath.x -= 10;
            // pressCount++;
            // std::cout << pressCount;
            // }
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            // {
            //   sf::Clock clock;
            //   snakePath.x += 10;
            // pressCount++;
            // std::cout << pressCount;
            // }
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            // {
            //   sf::Clock clock;
            //   snakePath.y += 10;
            // pressCount++;
            // std::cout << pressCount;
            // }
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            // {
            //   sf::Clock clock;
            //   snakePath.y -= 10;
            // pressCount++;
            // std::cout << pressCount;
            // }
            // sf::Time elapsed = clock.getElapsedTime();
            // if(elapsed.asSeconds() > .5 && sf::Event::KeyReleased){
            // do{
            //     snakePath.x -= 10 * elapsed.asSeconds();
            //     window.clear();
            //     window.draw(rec1);
            //     window.draw(rec2);
            //     window.draw(text);
            //     window.draw(testText);
            //     window.draw(testText1);
            //     rec3.setPosition(SnakeHead + snakePath);
            //     window.draw(rec3);
            //     break;
            // }while(!pressCount++);
            // }
            // }
            
          

            //rec3.move(snk.x,snk.y);
            //rec3.setPosition(snk.x,snk.y);
            //testText1.setString(std::to_string(snk.y));
           // testText.setString(std::to_string(snk.x));
           
            //std::cout<<std::to_string(snk.pos.x);  
            //std::cout<<std::to_string(snk.pos.y);        
           
            
            
            
            

            
            
        
        

            //window.clear();
            
            
         //    }
                //check location right before? or before and after? or pass data?
           
            
           
            
            
            
            
           // std::cout << "EVENT TRIGGERED\n";
        

         
        
        
        
        //     std::cout << "created\n";
        // }
            
            
           
            //bounderies do not need to be drawn
           // window.draw(w);
           // window.draw(e);
           // window.draw(s);
           // window.draw(n);
            //

            
            //snk.currLocation(snakeHead);
           // snk.KeyPressed();
            // testX = snakeHead.x;
            // testY = snakeHead.y;
            

            //left -= movementSpeed * 
        
        //&& !inner.intersects(boundsW));  //will need to be called redraw
      

        // if (inner.intersects(boundsW)){
        //     window.clear();
        // }
        
    
        
            
         

        //window.display();
        
        }
    }
       
    
return 0;
}
  