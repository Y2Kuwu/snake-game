#ifndef GETENG_H
#define GETENG_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <time.h>   
#include <deque>
#include "snakeBody.h"
#include "snacks.h"
#include "score.h"

class GetEng
{
private:


const unsigned int FPS = 60;
static const sf::Time TPF;
sf::Time last;


//bool impact(const sf::RectangleShape& , const sf::RectangleShape& );
//sf::RectangleShape getSegment(sf::Vector2f dirLoc);

std::vector<Snake> snake;
sf::RenderWindow win;

//sf::Event evt;

int foodIn;

int speed = 3;



sf::Vector2f headLocation;
sf::FloatRect headBox;
sf::Vector2f winSz;



//sf::Vector2f vel;
std::deque<int> dirQue;
int dir;

sf::Vector2f currPos;
sf::Vector2f prevPos;
bool dead;

public:
    sf::FloatRect food1;
    sf::FloatRect food2;
    //float deltaTime;
    //sf::Vector2f pos;
    sf::RectangleShape prompt;
    int countCycle; // from main

    //sf::Time deltaTime;


    GetEng();
    //Get(sf::RenderWindow *window);

    void getInit();

    //void inpListener();
    //void newDir(int newDir);
    //void newDir(sf::Vector2f newDir);


    void slither();
    void newSnk();
    void add();
    void eat();
    void death();
    void foodLocations(sf::FloatRect snack1, sf::FloatRect snack2);
    void upd();
    void runSnake();

    enum dirPush{UP,DOWN,LEFT,RIGHT};
    void pushDir(int dir);

    void drawSnake();
    void drawPrompt(int cycle);


    private:
   
    Score score;





};








#endif