// #include"snakeBody.h"
#include"getEng.h"
// using namespace start;

// //start::Snake::Snake(sf::RenderWindow *window)
// // Snake::Snake(sf::RenderWindow *window)
// // {
// //     //speed = 4;
// //     win = window;
// //     consumption = 1;

// //     //int x = win->getSize().x; 
// //     //int y = win->getSize().y; 
// //     int x = vel.x;
// //     int y = vel.y;
// //             //vel instead?
// //     {
// //         snakeBody.push_back(start::getSegment( sf::Vector2f(x,y)));
// //         posList.push_front(sf::Vector2<int>(-1,0));
// //     }
// //     stretch = false;
// // }


// //void start::
// void Snake::drawSnk()
// {
//     for (int snk = 1; snk < consumption; snk++) {
// 		win->draw( snakeBody[snk]);
// 	}
// 	win->draw( snakeBody[0] );
    
// }

// //bool start::
// bool Snake::isDead()
// {
//     for(int s = 0; s < snakeBody.size(); s++)
//     {
//     if(snakeBody[0].getPosition() == snakeBody[s].getPosition())
//     {
//         return true;
//     }
//     }
// }

// //sf::Vector2f start::
// sf::Vector2f  Snake::headPos()
// {
//     return headLocation;
// }


// //void start::
// void Snake::eat()
// {
//     if(foodIn+=1)
//     {
//         consumption = foodIn+1;
//         stretch = true;
//         sf::Vector2f newPos = snakeBody[consumption-1].getPosition();
//         snakeBody.push_back( start::getSegment(newPos));
//         posList.push_back(prevDir);
//         stretch = false;
//     }
// }

// //void start::
// void Snake::slither(sf::Vector2<int> dir)
// {
//     posList.push_front(dir);
//     prevDir = posList.back();
//     std::list<sf::Vector2<int>>::iterator snke = posList.begin();
//     int idx = 0;
//     while (snke != posList.end() && idx < consumption) {
// 		snakeBody[idx].move( pos );
//         //snakeBody[idx].move( pos );
// 		idx++;
// 		snke++;
//         snakeBody[0].getPosition() == headLocation;
// }
// }

// //void start::
// void Snake::dir(sf::Event e , float delta)
// {
//     e = evt;
//     if(e.key.code == sf::Keyboard::Left || evt.key.code == sf::Keyboard::A)
//     {
//         left = true;
//         vel.x = -50.0f;
//         vel.y = 0.0f;
//     }
//     if(e.key.code == sf::Keyboard::Right || evt.key.code == sf::Keyboard::D)
//     {
//         right = true;
//         vel.x = 50.0f;
//         vel.y = 0.0f;
//     }
//     if(e.key.code == sf::Keyboard::Up || evt.key.code == sf::Keyboard::W)
//     {
//         up = true;
//         vel.x = 0.0f;
//         vel.y = -50.0f;
//     }
//     if(e.key.code == sf::Keyboard::Down || evt.key.code == sf::Keyboard::D)
//     {
//         down = true;
//         vel.x = 0.0f;
//         vel.y = 50.0f;
//     }
//     pos += vel * delta;
//     //pos = dir// next
  
// }




// void direction(sf::Event e, float delta)
// {

#include"snakeBody.h"


Snake::Snake(sf::Vector2f startPos)
{
   bodySegment.setSize(sf::Vector2f(10,10));
   bodySegment.setPosition(startPos);
   bodySegment.setFillColor(sf::Color::Green);
   bodySegment.setOutlineColor(sf::Color::Black);
   bodySegment.setOutlineThickness(6); 
   
   GetEng().pos = startPos;
}

sf::Vector2f Snake::getPos()

{
    return GetEng().pos;
}

void Snake::setPos(sf::Vector2f newPos)
{
    GetEng().pos = newPos;
}

sf::RectangleShape Snake::getSeg()
{
    return bodySegment;
}

// void Snake::slither()
// {
//     bodySegment.setPosition(pos);
// }






    //pos = dir// next
  
