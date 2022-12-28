#include"snakeBody.h"
#include"get.h"

start::Snake::Snake(sf::RenderWindow *window)
{
    speed = 4;
    win = window;
    consumption = 1;

    int x = win->getSize().x; 
    int y = win->getSize().y; 
            //vel instead?
    {
        snakeBody.push_back(getSegment( sf::Vector2f(x,y)));
        posList.push_front(sf::Vector2<int>(-1,0));
    }
    stretch = false;
}

void start::Snake::drawSnk()
{
    for (int snk = 1; snk < consumption; snk++) {
		win->draw( snakeBody[snk]);
	}
	win->draw( snakeBody[0] );
}

bool start::Snake::isDead()
{
    for(int s = 0; s < snakeBody.size(); s++)
    {
    if(snakeBody[0].getPosition() == snakeBody[s].getPosition())
    {
        return true;
    }
    }
}

int start::Snake::eat(int food)
{
    if(food+=1)
    {
        consumption == food+1;
        stretch == true;
        sf::Vector2f newPos = snakeBody[consumption-1].getPosition();
        snakeBody.push_back( getSegment(newPos));
        posList.push_back(prevDir);
    }
}

void start::Snake::slither(sf::Vector2<int> dir)
{
    posList.push_front(dir);
    prevDir = posList.back();
    std::list<sf::Vector2<int>>::iterator snke = posList.begin();
    int idx = 0;
    while (snke != posList.end() && idx < consumption) {
		snakeBody[idx].move( speed*(*snke).x, speed*(*snke).y );
        //snakeBody[idx].move( pos );
		idx++;
		snke++;
}
}

void start::Snake::dir(sf::Event e , float delta)
{
    e = evt;
    if(e.key.code == sf::Keyboard::Left || evt.key.code == sf::Keyboard::A)
    {
        left = true;
        vel.x = -50.0f;
        vel.y = 0.0f;


    }
    if(e.key.code == sf::Keyboard::Right && evt.KeyReleased|| evt.key.code == sf::Keyboard::D)
    {
        right = true;
        vel.x = 50.0f;
        vel.y = 0.0f;

        
    }
    if(e.key.code == sf::Keyboard::Up || evt.key.code == sf::Keyboard::W)
    {
        up = true;
        vel.x = 0.0f;
        vel.y = -50.0f;

    }
    if(e.key.code == sf::Keyboard::Down || evt.key.code == sf::Keyboard::D)
    {
        down = true;
        vel.x = 0.0f;
        vel.y = 50.0f;

        
        
    }
    pos += vel * delta;
    //pos = dir// next
  
}




// void direction(sf::Event e, float delta)
// {

