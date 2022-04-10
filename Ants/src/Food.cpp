//
// Created by Mael Kerichard on 10/04/2022.
//

#include "Food.h"
#include "Renderer.h"

Food::Food(Environment *environment, const Vector2<float> &position, float quantity) : m_quantity(quantity),
                                                                                       Agent(environment, position,
                                                                                             MathUtils::circleRadius(
                                                                                                     quantity)) {}

float Food::getFoodQuantity() const {
    return m_quantity;
}


float Food::collectFood(const float quantity) {
    if (this->m_quantity > quantity) {
        this->m_quantity -= quantity;
        return quantity;
    } else {
        float collected = this->m_quantity;
        this->m_quantity = 0;
        return collected;
    }
}

void Food::update() {
//si la quantité de nourriture restante est égale à 0, l’agent doit passer en état destroy de manière à être détruit.
    Agent::setRadius(MathUtils::circleRadius(
            m_quantity));
    Renderer::getInstance()->drawCircle(Agent::getPosition(), Agent::getRadius(), Renderer::Color(154, 235, 38, 255));
    if (m_quantity <= 0) {
        Agent::setStatus(destroy);
    }
}
