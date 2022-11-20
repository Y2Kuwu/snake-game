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
        std::cout<<"line 30\n";
    }else if(totLen > 1){
        //head.front() = head.back(); // push current vector front to back
        head.push_back(this->curr); //new head.front()
        head.front().setPosition(this->deadSnake.getPosition()); //set position of prior
        head.front().setFillColor(sf::Color::Red);
        head.front().setSize(dupSize);
        snkTarget.draw(head.front(), snkState);
        std::cout<<"line 38\n";
        head.back().setFillColor(sf::Color::Red);
        head.back().setSize(dupSize);
        head.back().setPosition(this->deadSnake.getPosition());
        snkTarget.draw(head.back(), snkState);
    }
};

 void snakeBody::move()
 {
    this->deadSnake.setPosition(this->snkskin.getPosition());
    std::cout<<"line 49\n";
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        std::cout<<"line 52\n";
        this->posX = 0;
        this->posY -= 20.f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->posX = 0;
        this->posY += 20.f;
        std::cout<<"line 60\n";
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->posX -= 20.f;
        this->posY = 0;
        std::cout<<"line 66\n";
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->posX += 20.f;
        this->posY = 0;
        std::cout<<"line 72\n";
    }
        this->snkskin.move(posX, posY);
        sf::sleep(this->time);
        std::cout<<"line 76\n";
 };
 

    void snakeBody::ouroboros()
    {   std::cout<<"line here\n";
        if(this->snkskin.getGlobalBounds().intersects(curr.getGlobalBounds())){
       // posX , posY == 0;
        std::cout<<"line 84\n";
    }
    
        else if(this->snkskin.getGlobalBounds().intersects(this->hungerPtr->weNeedFood.getGlobalBounds())){
            float randX = std::rand();
            float randY = std::rand();
            sf::Vector2f setTheTable(randX,randY);
            std::cout<<"line 91\n";
            this->hungerPtr->weNeedFood.setPosition(setTheTable);
            this->addLength();
        }
    }

    void snakeBody::addLength()
    {
        if(this->totLen == 1){
            std::cout<<"line 100\n";
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
    
 


