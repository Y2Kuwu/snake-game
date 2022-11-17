#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
//put below into functions to be drawn repeatedly

class Game {
public:
    sf::Time GetElapsed();
    void RestartClock();
    sf::RectangleShape snake;
    enum Move {Left ='L', Right= 'R', Up='U', Down='D'};
    Move choice;
    void KeyPressed(Move choice);

     sf::Vector2f pos = snake.getPosition();

private:
    sf::Clock c_clock;
    sf::Time c_elapsed;
    };

sf::Time Game::GetElapsed() { return c_elapsed; }
void Game::RestartClock() { c_elapsed = c_clock.restart(); }
void Game::KeyPressed(Move choice){
   switch (choice) {
   case Left:
   sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
   std::cout<< pos.x <<std::endl;
   break;
   case Right:
   sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
   std::cout<< pos.x <<std::endl;
   break;
   case Up:
   sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
   std::cout<< pos.x <<std::endl;
   break;
   case Down:
   sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
   std::cout<< pos.x <<std::endl;
   break;
   
   }
}
    





int main(){


    // const float movementSpeed = 2.f;
    // float up,down,left,right = 0;
    
    // sf::Time time;
    // sf::Clock Clock;

    sf::RenderWindow window(sf::VideoMode(700, 700), "Snake");
    sf::RectangleShape rec1;
    sf::RectangleShape rec2;
    sf::RectangleShape rec3;
    //static

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
    //border boundaries
    sf::FloatRect boundsN = n.getGlobalBounds();
    sf::FloatRect boundsE = e.getGlobalBounds();
    sf::FloatRect boundsS = s.getGlobalBounds();
    sf::FloatRect boundsW = w.getGlobalBounds();
    n.setFillColor(sf::Color::Red);
    e.setFillColor(sf::Color::Red);
    s.setFillColor(sf::Color::Red);
    w.setFillColor(sf::Color::Red);

    rec1.setFillColor(sf::Color::Cyan);
    rec1.setSize(sf::Vector2f(670, 670));
    rec1.setPosition(15, 15);

    rec2.setFillColor(sf::Color::White);
    rec2.setSize(sf::Vector2f(650, 650));
    rec2.setOutlineColor(sf::Color::Black);
    rec2.setOutlineThickness(4);
    rec2.setPosition(25, 25);
    //

    rec3.setSize(sf::Vector2f(20,20));
    rec3.setOrigin(-340,-340);
    rec3.setFillColor(sf::Color::Red);

    std::vector <sf::RectangleShape> myRecs;
    myRecs.insert(myRecs.end(),{rec1,rec2});

    std::vector <sf::RectangleShape>::iterator recDis;

    sf::FloatRect inner = rec3.getGlobalBounds();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
              if (event.type == sf::Event::Resized)
    {
             sf::FloatRect visibleArea(-600, -200, event.size.width, event.size.height);
             window.setView(sf::View(visibleArea));
    }
            
        }
        
        for (recDis = myRecs.begin(); recDis != myRecs.end(); ++recDis) {  //will need to be called for redraw
            window.draw(*recDis);  
        }
        
      
            window.clear();
            window.draw(rec1);
            window.draw(rec2);
            window.draw(rec3);
            window.draw(w);
            window.draw(e);
            window.draw(s);
            window.draw(n);
            //left -= movementSpeed * 
            rec3.move(-.2,0);
        
        //&& !inner.intersects(boundsW));  //will need to be called redraw
      
       


        //  switch(choice){
        //     case Left:

        //  }

        // if (inner.intersects(boundsW)){
        //     window.clear();
        // }
        
         
        
            
         

        window.display();
        
        }
       
    
return 0;
}
  