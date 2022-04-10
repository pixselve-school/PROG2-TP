//
// Created by Mael Kerichard on 10/04/2022.
//

#ifndef ANTS_FOOD_H
#define ANTS_FOOD_H


#include "Agent.h"
#include "MathUtils.h"

class Food: public Agent {
private:
    float m_quantity;
public:
    Food(Environment *environment, const Vector2<float> &position, float quantity);

    float getFoodQuantity() const;

    float collectFood(float quantity);

    void update() override;

};


#endif //ANTS_FOOD_H
