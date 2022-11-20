#include "snakeBody.h"
#include <typeinfo>

std::vector<sf::RectangleShape>head;
sf::Vector2f dupSize(20.f,20.f);

snakeBody::snakeBody()
{
    totLen = 0;

    time = sf::seconds(0.2f);
    snkSkin.setSize(sf::Vector2f(20,20));
    snkSkin.setOrigin(90,90);
    snkSkin.setFillColor(sf::Color::Red);
    
};




void snakeBody::draw(sf::RenderTarget& snkTarget, sf::RenderStates snkState) const
{   //              //this particular rectangle draw in this state
    
    snkTarget.draw(snkSkin, snkState);
    if(this->totLen == 1){
        
       
        //head.front() = this->curr[0];
        //std::cout << typeid(head.front()).name();
        //head.front().setPosition(deadSnake.getPosition());
        curr[0].setPosition(deadSnake.getPosition());
        snkTarget.draw(curr[0], snkState);
        //head.push_back(this->curr[0]);
        std::cout<<"line 30\n";
    }else if(totLen > 1){
        for(int i=this->totLen-1;i>0;i--){
        //head.front() = head.back(); // push current vector front to back
        // head.push_back(this->curr[i]); //new head.front()
        // head.front().setPosition(this->curr[i-1].getPosition()); //set position of prior
        // head.front().setFillColor(sf::Color::Red);
        // head.front().setSize(dupSize);
        //head.push_back(curr[i]); //new head.front()
         curr[i].setPosition(curr[i-1].getPosition()); //set position of prior
         curr[i].setFillColor(sf::Color::Red);
         curr[i].setSize(dupSize);
        snkTarget.draw(curr[i], snkState);
        std::cout<<"line 38\n";
        //check for error line 43 pos 0?
        curr[0].setFillColor(sf::Color::Red);
        curr[0].setSize(dupSize);
        curr[0].setPosition(deadSnake.getPosition());
        snkTarget.draw(curr[0], snkState);
        //
    }
    }
};

 void snakeBody::move()
 {
    this->deadSnake.setPosition(this->snkSkin.getPosition());
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
        this->snkSkin.move(posX, posY);
        //sf::sleep(this->time);
        std::cout<<"line 76\n";
 };
 

    void snakeBody::ouroboros()
    {   std::cout<<"line here\n";
    for(int i=0; i< totLen; i++)
    {
        std::cout<<"here";
        sf::FloatRect bb = this->snkSkin.getGlobalBounds();
        if(bb.intersects(curr[i].getGlobalBounds())){
                //check 87 for error //convert to for loop track idx
       // posX , posY == 0;
        std::cout<< bb.height;
        std::cout<<"line 84\n";
    }
    
         if(this->snkSkin.getGlobalBounds().intersects(this->hungerPtr->weNeedFood.getGlobalBounds())){
            float randX = std::rand();
            float randY = std::rand();
            sf::Vector2f setTheTable(randX,randY);
            std::cout<<"line 91\n";
            this->hungerPtr->weNeedFood.setPosition(setTheTable);
            this->addLength();
        }
    }
    }
    void snakeBody::addLength()
    {
        if(this->totLen == 0){
            std::cout<<"line 100\n";
            this->totLen++;
            //this->curr.setPosition(this->curr.getPosition());
            curr = new sf::RectangleShape [this->totLen];
            curr[0].setFillColor(sf::Color::Red);
            curr[0].setSize(dupSize);
            }
            else{
            copy = new sf::RectangleShape [this->totLen];
            for(int i =0; i < this->totLen; i++){
                this->copy[i].setPosition(this->curr[i].getPosition());
            }
            this->totLen++;
            delete [] curr;
            this->curr = new sf::RectangleShape [this->totLen];
             for(int i =0; i < this->totLen; i++){
            this->curr[i].setPosition(this->copy[i].getPosition());

             }
             delete [] copy;
            }
            }

            //this->curr = new sf::RectangleShape [this->totLen];
            // totLen = head.size();
            // //sf::RectangleShape segment;
            // //tail = head.begin();
            // //tail = head.insert(tail, curr[totLen]);
            // curr[totLen].setFillColor(sf::Color::Red);
            // curr[totLen].setSize(dupSize);
        

    
    
 


