//
// Created by Mael Kerichard on 10/04/2022.
//

#include "Anthill.h"
#include "../utils/Renderer.h"
#include "AntWithRules.h"
#include "../interface/NotificationBox.h"

Anthill::Anthill(Environment *environment, const Vector2<float> &position) : foodQuantity(0),
                                                                             Agent(environment, position,
                                                                                   10) {}

void Anthill::update() {
    Renderer::getInstance()->drawCircle(Agent::getPosition(), Agent::getRadius(), Renderer::Color(0, 0, 255, 255));
    Renderer::getInstance()->drawString(Agent::getPosition(), "food: " + std::to_string((int) foodQuantity));
//    ant creating mechanism
    if (foodQuantity >= FOOD_REQUIRED_FOR_A_NEW_ANT) {
        new AntWithRules(getEnvironment(), this);
        NotificationBox::getInstance()->addNotification(Notification("Naissance d'une fourmi"));
        foodQuantity -= FOOD_REQUIRED_FOR_A_NEW_ANT;
    }
}

void Anthill::depositFood(const float quantity) {
    foodQuantity += quantity;
}
