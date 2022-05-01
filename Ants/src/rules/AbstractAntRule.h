//
// Created by Mael Kerichard on 10/04/2022.
//

#ifndef ANTS_ABSTRACTANTRULE_H
#define ANTS_ABSTRACTANTRULE_H


#include "../ants/AbstractRule.h"
#include "../ants/AntBase.h"
#include "../ants/AntBasePheromone.h"

class AbstractAntRule : public AbstractRule {
public:
    explicit AbstractAntRule(AntBasePheromone *targetAnt);

private:
    AntBasePheromone *targetAnt;
public:
    AntBasePheromone *getTargetAnt() const;
};


#endif //ANTS_ABSTRACTANTRULE_H
