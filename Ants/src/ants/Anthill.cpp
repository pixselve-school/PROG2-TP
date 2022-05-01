//
// Created by Mael Kerichard on 10/04/2022.
//

#include "Anthill.h"
#include "../utils/Renderer.h"

Anthill::Anthill(Environment *environment, const Vector2<float> &position) : foodQuantity(0),
                                                                             Agent(environment, position,
                                                                                   10) {}

void Anthill::update() {
    Renderer::getInstance()->drawCircle(Agent::getPosition(), Agent::getRadius(), Renderer::Color(0, 0, 255, 255));
}

void Anthill::depositFood(const float quantity) {
    foodQuantity += quantity;
}
