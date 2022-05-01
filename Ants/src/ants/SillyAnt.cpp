//
// Created by Mael Kerichard on 10/04/2022.
//

#include "SillyAnt.h"
#include "../ant-environment/Food.h"
#include "../utils/Timer.h"

SillyAnt::SillyAnt(Environment *environment, Anthill *parentAnthill)
        : AntBase(environment, parentAnthill) {

}

void SillyAnt::update() {
    AntBase::update();
    if (hasFood()) {
        // partie retour à la fourmilière
        if (!LocalizedEntity::perceive<Anthill>().empty() &&
            LocalizedEntity::perceive<Anthill>().front() == getParentAnthill()) {
            // la fourmi a trouvé la fourmilière
            getParentAnthill()->depositFood(dropFood());

        } else {
            // la fourmi n'a pas trouvé la fourmilière
            rotateToTarget(getParentAnthill()->getPosition());
            move();
        }
    } else {
        // partie exploration
        if (LocalizedEntity::perceive<Food>().empty()) {
            // la fourmi n'a pas trouvé de nourriture
            auto angle = MathUtils::random((-MathUtils::pi / 10) * Timer::dt(), (MathUtils::pi / 10) * Timer::dt());
            rotate(angle);
            move();
        } else {
            // la fourmi a trouvé de la nourriture
            float collectedFood = LocalizedEntity::perceive<Food>().front()->collectFood(MAX_FOOD);
            grabFood(collectedFood);
        }
    }
}
