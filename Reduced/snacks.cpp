#include "snacks.h"

Snacks::Snacks(sf::Vector2f snackPos)
{
    snack.setPosition(snackPos);
    snack.setRadius(sz);
    snack.setFillColor(sf::Color::Red);
    snack.setOutlineColor(sf::Color::Black);
    snack.setOutlineThickness(2);

    collide.setSize(sf::Vector2f(20,20));
    //collide.setPosition(backPos);
    collide.setPosition(snackPos);
    //collide.setOutlineColor(sf::Color::Black);
    //collide.setOutlineThickness(2);
    //collide.setFillColor(sf::Color::Black);
    globals = collide.getGlobalBounds();

    snackPos = snackBounds;
}

sf::Vector2f Snacks::getBounds() 
{
    return snackBounds;
}

void Snacks::setBounds(sf::Vector2f pos)
{
    snackBounds = pos;
}

sf::CircleShape Snacks::getSnack()
{
    return snack;
}

void Snacks::upd()
{
    snack.setPosition(snackBounds);
}

// Collision::Collision(sf::Vector2f snackPos)
// {
//     collide.setSize(backSz);
//     //collide.setPosition(backPos);
//     collide.setPosition(snackPos);
//     collide.setOutlineColor(sf::Color::Black);
//     collide.setOutlineThickness(2);
//     collide.setFillColor(sf::Color::Black);
//     globals = collide.getGlobalBounds();
//     snackPos = impactBounds;
// }

// sf::Vector2f Collision::getImpact() 
// {
//     return impactBounds;
// }

// void Collision::setImpact(sf::Vector2f newPos)
// {
//     impactBounds = newPos;
// }

// sf::RectangleShape Collision::getCollision()
// {
//     return collide;
// }

// void Collision::upd()
// {
//     collide.setPosition(impactBounds);
// }