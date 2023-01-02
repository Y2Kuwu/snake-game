#ifndef GETENG_H
#define GETENG_H
#include <SFML/Graphics.hpp>
#include <time.h>   
#include "snakeBody.h"
#include "snacks.h"
#include "score.h"

class GetEng
{
private:
//f::Clock init;

const unsigned int FPS = 60;
static const sf::Time TPF;

//bool impact(const sf::RectangleShape& , const sf::RectangleShape& );
//sf::RectangleShape getSegment(sf::Vector2f dirLoc);

std::vector<Snake> snake;
sf::RenderWindow win;

sf::Event evt;

int foodIn;

int speed;

sf::Vector2f headLocation;
sf::FloatRect headBox;
sf::Vector2f winSz;
sf::FloatRect food1;
sf::FloatRect food2;


sf::Vector2f vel;

sf::Vector2f prevPos;
bool dead;

public:
    float deltaTime;
    sf::Vector2f pos;
    sf::RectangleShape prompt;
    int countCycle; // from main

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
    void death();
    void foodLocations(sf::FloatRect snack1, sf::FloatRect snack2);
    void checkFood();
    void runSnake();

    //void slither(float delta);
    void slither();
    void drawSnake();
    void drawPrompt(int cycle);

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