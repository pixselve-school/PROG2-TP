//
// Created by Mael Kerichard on 10/04/2022.
//

#ifndef ANTS_ABSTRACTANTRULE_H
#define ANTS_ABSTRACTANTRULE_H


#include "AbstractRule.h"
#include "AntBase.h"
#include "AntBasePheromone.h"

class AbstractAntRule: public AbstractRule {
public:
    explicit AbstractAntRule(AntBasePheromone *targetAnt);

private:
    AntBasePheromone * targetAnt;
public:
    AntBasePheromone *getTargetAnt() const;
};


#endif //ANTS_ABSTRACTANTRULE_H
