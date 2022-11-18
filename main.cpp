#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
//put below into functions to be drawn repeatedly

class Game {
public:
    sf::RectangleShape snek;
    //sf::Event push;
    //sf::Vector2f pos;
    Game(sf::RectangleShape snake);
    sf::Time GetElapsed();
    void RestartClock();
    float x; 
    float y;
    sf::Vector2f snakeLocation;

    sf::Vector2f pos;
    sf::Vector2f KeyIsPressed(sf::Event push, sf::RectangleShape snek);//, sf::Vector2f pos);
   
    //sf::Vector2f currLocation(sf::Vector2f snakeLocation);
    //void "food"location / generated is consumed T/F
    //void length / points()

   //enum Move {Left ='L', Right= 'R', Up='U', Down='D'};
    //rework enumeration sfml already has keys enumerated
   // Move choice;
    
   
     
     

private:
    sf::Clock c_clock; 
    sf::Time c_elapsed; 
   // sf::Vector2f pos;

};
Game::Game(sf::RectangleShape snake){
     snek = snake;
}
//sf::Vector2f Game::currLocation(sf::Vector2f s){ //receiving x and y successfully
    
//}

sf::Time Game::GetElapsed() { return c_elapsed; }
void Game::RestartClock() { c_elapsed = c_clock.restart(); }
sf::Vector2f Game::KeyIsPressed(sf::Event push, sf::RectangleShape snek){// , sf::Vector2f pos){
   //switch (push.type == sf::Event::KeyPressed && push.key.code) {
   switch (push.key.code) {
   case sf::Keyboard::Left:
   snek.getPosition() == pos;
   pos.x -= 1;
   pos.y = 0;
   //set location here?
   std::cout<< "left" <<std::endl;
   std::cout<< std::to_string(pos.x) <<std::endl;
   return (pos); //return new value?
   break;
   
   case sf::Keyboard::Right:
   std::cout<< "right" <<std::endl;
   break;

   case sf::Keyboard::Up:
   std::cout<< "up" <<std::endl;
   break;

   case sf::Keyboard::Down:
   std::cout<< "down" <<std::endl;
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

    Game snk(rec3);

    

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
    sf::Vector2f snakeHead = rec3.getPosition();
    sf::Vector2f newSnakeHead;
    //

    std::vector <sf::RectangleShape> myRecs;
    myRecs.insert(myRecs.end(),{rec1,rec2});

    std::vector <sf::RectangleShape>::iterator recDis;

    

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
    sf::Text testText;
    sf::Text testText1;
    sf::Font def;
    def.loadFromFile("MG.ttf");
    testText.setFont(def);
    testText.setCharacterSize(20);
    testText.setStyle(sf::Text::Regular);
    testText.setString(std::to_string(snakeHead.x));
    testText.setPosition(sf::Vector2f(275,120));
    testText.setColor(sf::Color::Black);

    testText1.setFont(def);
    testText1.setCharacterSize(20);
    testText1.setStyle(sf::Text::Regular);
    testText1.setString(std::to_string(snakeHead.y));
    testText1.setPosition(sf::Vector2f(275,140));
    testText1.setColor(sf::Color::Black);
    

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
            // 
            
            // window.draw(testText);
            // window.draw(testText1);
            //std::cout << std::to_string(snakeHead.x);
            //added event trigger
        while(event.type == sf::Event::KeyPressed)
        {
             window.clear();
            
            snk.KeyIsPressed(event, rec3);
            //window.clear();
            //rec3.move(-2.0f,0);
            // window.draw(rec1);
            // window.draw(rec2);
            //window.draw(text);
            // window.draw(rec1);
            // window.draw(rec2);
            //snk.snakeLocation = snakeHead;
            rec3.move(snk.pos.x,snk.pos.y);
            //rec3.setPosition(newSnakeHead);
            std::cout<<"printed"; 
            std::cout<<std::to_string(snk.pos.x);  
             std::cout<<std::to_string(snk.pos.y);        
            window.draw(text);
            window.draw(testText);
            window.draw(testText1);
            window.draw(rec3);
            if(event.type == !sf::Event::KeyPressed);
            break;
        }

            //window.clear();
            
            
         //    }
                //check location right before? or before and after? or pass data?
           
            
           
            
            
            
            
           // std::cout << "EVENT TRIGGERED\n";
        

         
        
        
        // for (recDis = myRecs.begin(); recDis != myRecs.end(); ++recDis) {  //will need to be called for redraw
        //     window.draw(*recDis);  
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
        
         
        
            
         

        window.display();
        
        }
    }
       
    
return 0;
}
  