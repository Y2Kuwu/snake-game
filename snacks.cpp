#include "snacks.h"

Snacks::Snacks(sf::Vector2f snackPos)
{
    snack.setPosition(snackPos);
    snack.setRadius(sz);
    snack.setFillColor(sf::Color::Red);
    snack.setOutlineColor(sf::Color::Black);
    snack.setOutlineThickness(2);

    collide.setSize(sf::Vector2f(20,20));
    collide.setPosition(snackPos);
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
