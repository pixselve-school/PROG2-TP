//
// Created by Mael Kerichard on 10/04/2022.
//

#ifndef ANTS_PHEROMONE_H
#define ANTS_PHEROMONE_H


#include "../ants/Agent.h"

class Pheromone : public Agent {
private:
    float quantity;
    constexpr static float EVAPORATION_RATE = 0.01;
public:
    Pheromone(Environment *environment, const Vector2<float> &position, float quantity);

/**
     * Récupère la quantité de pheromones
     * @return la quantité de pheromones
     */
    float getQuantity() const;

    /**
     * Ajoute des pheromones
     * @param quantity la quantité de pheromones à ajouter
     */
    void addQuantity(float quantity);

    void update() override;

    /**
     * Évaporation des pheromones
     */
    void evaporate();
};


#endif //ANTS_PHEROMONE_H
