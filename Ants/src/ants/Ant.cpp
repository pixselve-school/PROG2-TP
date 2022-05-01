//
// Created by Mael Kerichard on 10/04/2022.
//

#include "Ant.h"
#include "../ant-environment/Food.h"
#include "../utils/Timer.h"

Ant::Ant(Environment *environment, Anthill *parentAnthill) : AntBasePheromone(environment, parentAnthill) {

}

void Ant::update() {
    AntBasePheromone::update();
    if (hasFood()) {
        if (!LocalizedEntity::perceive<Anthill>().empty() &&
            LocalizedEntity::perceive<Anthill>().front() == getParentAnthill()) {
            // Si la fourmi transporte de la nourriture et se trouve sur son nid, elle dépose la nourriture et
            //fait demi-tour.
            getParentAnthill()->depositFood(dropFood());
            turnAround();
        } else {
            // Si la fourmi transporte de la nourriture et ne se trouve pas sur son nid, elle retourne au nid.
            //Pour ce faire (1) elle se tourne vers le nid, (2) si elle perçoit des phéromones dans la direction du nid, elle les suit (choosePheromone), si elle ne perçoit pas de phéromones, elle se dirige vers le nid en ligne droite.
            rotateToTarget(getParentAnthill()->getPosition());
            auto pheromones = choosePheromone();
            if (pheromones != nullptr) {
                rotateToTarget(pheromones->getPosition());
            }
            move();
        }
    } else {
        if (LocalizedEntity::perceive<Food>().empty()) {
            auto foodInView = LocalizedEntity::perceive<Food>(getDirection(), OPENING_ANGLE, MAX_DISTANCE_VIEW_FOOD);
            if (foodInView.empty()) {
                auto pheromones = choosePheromone();
                if (pheromones != nullptr) {
                    rotateToTarget(pheromones->getPosition());
                } else {
                    auto angle = MathUtils::random((-MathUtils::pi / 10) * Timer::dt(),
                                                   (MathUtils::pi / 10) * Timer::dt());
                    rotate(angle);
                }
                move();
            } else {
                // Si la fourmi ne transporte pas de nourriture mais perçoit la nourriture, elle se déplace vers la
                //nourriture.
                rotateToTarget(foodInView.front()->getPosition());
                move();
            }
        } else {
            // Si la fourmi ne transporte pas de nourriture et se trouve sur de la nourriture, elle en ramasse.
            grabFood(LocalizedEntity::perceive<Food>().front()->collectFood(MAX_FOOD));
        }
    }
}
