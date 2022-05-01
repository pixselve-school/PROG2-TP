//
// Created by Mael Kerichard on 10/04/2022.
//

#ifndef ANTS_ANTBASEPHEROMONE_H
#define ANTS_ANTBASEPHEROMONE_H


#include "AntBase.h"
#include "../ant-environment/Pheromone.h"

class AntBasePheromone : public AntBase {
protected:
    const static float MAX_DISTANCE_VIEW_PHEROMONE;
    const static float PHEROMONE_AMOUNT_TO_DROP;
    const static float PHEROMONE_AMOUNT_TO_DROP_WHEN_CARRYING_FOOD;
public:

    AntBasePheromone(Environment *environment, Anthill *parentAnthill);

    /**
     * Dépose des phéromones
     * @param q quantité de phéromones à déposer
     */
    void putPheromone(float q);

    /**
     * percevoir les phéromones à une distance maximale de 8 cm, (2) de choisir au hasard une phéromone à suivre en fonction de sa concentration.
     * @return une phéromone à suivre en fonction de sa concentration
     */
    Pheromone *choosePheromone() const;

    void update() override;
};


#endif //ANTS_ANTBASEPHEROMONE_H
