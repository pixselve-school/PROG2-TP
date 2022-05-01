//
// Created by Mael Kerichard on 10/04/2022.
//

#include "Pheromone.h"
#include "../utils/Timer.h"
#include "../utils/Renderer.h"

void Pheromone::update() {
    evaporate();
    if (quantity < 0.01) {
        setStatus(destroy);
    }
    Renderer::getInstance()->drawCircle(Agent::getPosition(), Agent::getRadius(),
                                        Renderer::Color(0, 128, 128, std::min(255.0f, quantity)));
}

void Pheromone::evaporate() {
    quantity -= EVAPORATION_RATE * quantity * Timer::dt();
}

float Pheromone::getQuantity() const {
    return quantity;
}

void Pheromone::addQuantity(float quantity) {
    this->quantity += quantity;
}

Pheromone::Pheromone(Environment *environment, const Vector2<float> &position, float quantity) : quantity(quantity), Agent(environment,
                                                                                       position, 2) {}
