//
// Created by Mael Kerichard on 10/04/2022.
//

#include "AntBase.h"
#include "Renderer.h"
#include "Timer.h"

void AntBase::update() {
    auto color = hasFood() ? Renderer::Color(128, 255, 128, 255) : Renderer::Color(255, 255, 255, 255);
    Renderer::getInstance()->drawCircle(Agent::getPosition(), Agent::getRadius(), color);
    life -= Timer::dt();
    if (life <= 0) {
        Agent::setStatus(destroy);
    }
}

bool AntBase::hasFood() const {
    return foodCarrying > 0;
}

void AntBase::grabFood(float amount) {
    foodCarrying += std::max(amount, 5.0f);
}

float AntBase::dropFood() {
    auto tempFoodCarrying = foodCarrying;
    foodCarrying = 0;
    return tempFoodCarrying;
}

void AntBase::rotate(float angle) {
    direction = direction.rotate(angle);
}

void AntBase::turnAround() {
    direction = direction.rotate(MathUtils::pi);
}

void AntBase::rotateToTarget(const Vector2<float> &target) {
    direction = getPosition().direction(target);
}

void AntBase::move() {
    translate(direction * speed * Timer::dt());
}

AntBase::AntBase(Environment *environment, Anthill *parentAnthill, float life, float speed) : parentAnthill(
        parentAnthill), foodCarrying(0), speed(speed), direction(Vector2<float>::random()),
                                                                                              life(life),
                                                                                              Agent(environment,
                                                                                                    parentAnthill->getPosition()) {
    assert(life >= 1000 && life <= 2500);
}

Anthill *AntBase::getParentAnthill() const {
    return parentAnthill;
}

const Vector2<float> &AntBase::getDirection() const {
    return direction;
}


const float AntBase::OPENING_ANGLE = MathUtils::piDiv2;
const float AntBase::MAX_FOOD = 5;
const float AntBase::MAX_DISTANCE_VIEW_FOOD = 3;