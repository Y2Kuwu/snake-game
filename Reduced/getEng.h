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

int speed;

sf::Vector2f randPos1;
sf::Vector2f randPos2;
std::vector<Snacks>snackSack;
//std::vector<Collision>impact;


sf::Vector2f headLocation;
sf::FloatRect headBox;
sf::FloatRect bodyBox;

sf::Vector2f winSz;

int randomPosX1;
int randomPosY1;
int randomPosX2;
int randomPosY2;

sf::Vector2f collisionBox;

//sf::Vector2f vel;
std::deque<int> dirQue;
int dir;


bool dead;
bool start;
bool flash;

public:
    sf::FloatRect food1;
    sf::FloatRect food2;
    sf::RectangleShape prompt;
    sf::RectangleShape back;
    sf::RectangleShape backOutline;


    int countCycle; // from main
    bool callRand;
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
    void background();
    void checkStart();
    void in();
    void sleepAndEat();
    //void drawFood(Snacks);
    void setSnack();

    enum dirPush{UP,DOWN,LEFT,RIGHT};
    void pushDir(int dir);

    void drawSnake();
    void drawSnack();
    void drawPrompt(int cycle);


    private:
   
    Score score;
    //Collision collision;



};








#endif