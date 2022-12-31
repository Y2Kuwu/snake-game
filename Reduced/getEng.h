#ifndef GETENG_H
#define GETENG_H
#include <SFML/Graphics.hpp>
#include "snakeBody.h"
#include "snacks.h"
#include "score.h"

class GetEng
{
private:

//bool impact(const sf::RectangleShape& , const sf::RectangleShape& );
//sf::RectangleShape getSegment(sf::Vector2f dirLoc);

std::vector<Snake> snake;
sf::RenderWindow win;

sf::Event evt;
float deltaTime;
int foodIn;
int countCycle; // from main
int speed;

sf::Vector2f headLocation;
sf::FloatRect headBox;
sf::Vector2f winSz;
sf::FloatRect food1;
sf::FloatRect food2;

sf::Vector2f vel;

sf::Vector2f prevPos;

public:
    sf::Vector2f pos;
    GetEng();
    //Get(sf::RenderWindow *window);

    void getInit();

    //void inpListener();
    //void newDir(int newDir);
    //void newDir(sf::Vector2f newDir);
    void newDir();

    void newSnk();
    void add();
    void eat();
    void foodLocations(sf::FloatRect snack1, sf::FloatRect snack2);

    void slither(sf::Event evt , float delta);
    void drawSnake();

    void pushDir();
    void updateSnake();
   

    

    private:
    // void loop(); //game loop
    // void set(); // set static
    // void dead(); //check alive
    // void load();
    // void delta(float d); // get time
    
    Score score;
    // Snake snake;
    // sf::RenderWindow win;





};








#endif