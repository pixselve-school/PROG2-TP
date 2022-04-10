//
// Created by Mael Kerichard on 10/04/2022.
//

#include "AbstractAntRule.h"

AbstractAntRule::AbstractAntRule(AntBasePheromone *targetAnt) : targetAnt(targetAnt) {}

AntBasePheromone *AbstractAntRule::getTargetAnt() const {
    return targetAnt;
}
