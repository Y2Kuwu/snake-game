#include"snakeBody.h"

Snake::Snake(sf::RenderWindow *window)
{
    speed = 4;
    win = window;
    consumption = 1;

    int x = win->getSize().x; 
    int y = win->getSize().y; 

    {
        snakeBody.push_back(getSegment( sf::Vector2f(x,y)));
        posList.push_front(sf::Vector2<int>(-1,0));
    }
    stretch = false;
}

void Snake::drawSnk()
{
    for (int snk = 1; snk < consumption; snk++) {
		win->draw( snakeBody[snk]);
	}
	win->draw( snakeBody[0] );
}

bool Snake::isDead()
{
    for(int s = 0; s < snakeBody.size(); s++)
    {
    if(snakeBody[0].getPosition() == snakeBody[s].getPosition())
    {
        return true;
    }
    }
}

int Snake::eat(int food)
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

void Snake::slither(sf::Vector2<int> dir)
{
    posList.push_front(dir);
    prevDir = posList.back();
    std::list<sf::Vector2<int>>::iterator snke = posList.begin();
    int idx = 0;
    while (snke != posList.end() && idx < consumption) {
		snakeBody[idx].move( speed*(*snke).x, speed*(*snke).y );
		idx++;
		snke++;
}
}

