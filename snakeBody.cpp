#include "snakeBody.h"

std::vector<sf::RectangleShape>head;
sf::Vector2f dupSize(20.f,20.f);

snakeBody::snakeBody()
{
    totLen = 1;

    time = sf::seconds(0.2f);
    snkskin.setSize(sf::Vector2f(20,20));
    snkskin.setOrigin(-340,-340);
    snkskin.setFillColor(sf::Color::Red);
    
};




void snakeBody::draw(sf::RenderTarget& snkTarget, sf::RenderStates snkState) const
{   //              //this particular rectangle draw in this state
    
    snkTarget.draw(this->snkskin, snkState);
    if(totLen == 1){
        
        head.push_back(this->curr);
        head.front() = this->curr;
        head.front().setPosition(this->deadSnake.getPosition());
        snkTarget.draw(this->curr , snkState);
    }else if(totLen > 1){
        //head.front() = head.back(); // push current vector front to back
        head.push_back(this->snkskin); //new head.front()
        head.front().setPosition(this->deadSnake.getPosition()); //set position of prior
        head.front().setFillColor(sf::Color::Red);
        head.front().setSize(dupSize);
        snkTarget.draw(head.front(), snkState);

        head.back().setFillColor(sf::Color::Red);
        head.back().setSize(dupSize);
        head.back().setPosition(this->deadSnake.getPosition());
        snkTarget.draw(head.back(), snkState);
    }
};

 void snakeBody::move()
 {
    this->deadSnake.setPosition(this->snkskin.getPosition());

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->posX = 0;
        this->posY -= 20.f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->posX = 0;
        this->posY += 20.f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->posX -= 20.f;
        this->posY = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->posX += 20.f;
        this->posY = 0;
    }
        this->snkskin.move(posX, posY);
        sf::sleep(this->time);
 };
 

    void snakeBody::ouroboros()
    {
        if(this->snkskin.getGlobalBounds().intersects(head.front().getGlobalBounds())){
        posX && posY == 0;

    }
    
        if(this->snkskin.getGlobalBounds().intersects(this->hungerPtr->weNeedFood.getGlobalBounds())){
            float randX = std::rand();
            float randY = std::rand();
            sf::Vector2f setTheTable(randX,randY);
            
            this->hungerPtr->weNeedFood.setPosition(setTheTable);
            this->addLength();
        }
    }

    void snakeBody::addLength()
    {
        if(this->totLen == 1){
            this->totLen++;
            this->prev.setPosition(this->curr.getPosition());
            //this->curr = new sf::RectangleShape [this->totLen];
            totLen = head.size();
            sf::RectangleShape segment;
            tail = head.begin();
            tail = head.insert(tail, segment);
            segment.setFillColor(sf::Color::Red);
            segment.setSize(dupSize);
        }

    }
    
 


