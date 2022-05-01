//
// Created by Mael Kerichard on 10/04/2022.
//

#ifndef ANTS_ANTHILL_H
#define ANTS_ANTHILL_H


static const int FOOD_REQUIRED_FOR_A_NEW_ANT = 50;

#include "Agent.h"

class Anthill : public Agent {
private:
    float foodQuantity;
public:
    Anthill(Environment *environment, const Vector2<float> &position);

    void update() override;

    void depositFood(float quantity);
};


#endif //ANTS_ANTHILL_H
