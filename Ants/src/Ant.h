//
// Created by Mael Kerichard on 10/04/2022.
//

#ifndef ANTS_ANT_H
#define ANTS_ANT_H


#include "AntBasePheromone.h"

class Ant : public AntBasePheromone {
public:
    Ant(Environment *environment, Anthill *parentAnthill);

    void update() override;

};


#endif //ANTS_ANT_H
