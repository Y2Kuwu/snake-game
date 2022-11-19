#include "food.h"

    food::food(){
    weNeedFood.setRadius(10);
    weNeedFood.setFillColor(sf::Color::Yellow);
    weNeedFood.setOutlineColor(sf::Color::Black);
    
}


   void food::draw(sf::RenderTarget& snkTarget, sf::RenderStates snkState) const
    {
        snkTarget.draw(this->weNeedFood, snkState);
    }