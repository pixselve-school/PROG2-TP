//
// Created by Mael Kerichard on 10/04/2022.
//

#include "AntBasePheromone.h"
#include "Pheromone.h"

void AntBasePheromone::putPheromone(float q) {
    if (LocalizedEntity::perceive<Pheromone>().empty()) {
        new Pheromone(getEnvironment(), getPosition(), q);
    } else {
        LocalizedEntity::perceive<Pheromone>().front()->addQuantity(q);
    }
}

const float AntBasePheromone::MAX_DISTANCE_VIEW_PHEROMONE = 8;
const float AntBasePheromone::PHEROMONE_AMOUNT_TO_DROP = 10;
const float AntBasePheromone::PHEROMONE_AMOUNT_TO_DROP_WHEN_CARRYING_FOOD = 100;

Pheromone *AntBasePheromone::choosePheromone() const {
    auto perceivedPheromones = LocalizedEntity::perceive<Pheromone>(getDirection(), OPENING_ANGLE,
                                                                    MAX_DISTANCE_VIEW_PHEROMONE);
    if (perceivedPheromones.empty()) {
        return nullptr;
    }

    std::vector<float> probaTable(perceivedPheromones.size(), 0);

    std::transform(perceivedPheromones.begin(), perceivedPheromones.end(), probaTable.begin(),
                   [](Pheromone * value) {
                       return value->getQuantity();
                   });

    auto chosenIndex = MathUtils::randomChoose(probaTable);
    return perceivedPheromones[chosenIndex];
}

void AntBasePheromone::update() {
    AntBase::update();
    if (hasFood()) {
        putPheromone(PHEROMONE_AMOUNT_TO_DROP_WHEN_CARRYING_FOOD);
    } else {
        putPheromone(PHEROMONE_AMOUNT_TO_DROP);
    }
}

AntBasePheromone::AntBasePheromone(Environment *environment, Anthill *parentAnthill)
        : AntBase(environment, parentAnthill) {

}

