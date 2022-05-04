//
// Created by Mael Kerichard on 10/04/2022.
//

#ifndef ANTS_ANTBASE_H
#define ANTS_ANTBASE_H


#include "Agent.h"
#include "Anthill.h"

class AntBase : public Agent {
private:
    Anthill *parentAnthill;
public:
    Anthill *getParentAnthill() const;

private:
    float speed;
    float life;
    float foodCarrying;
    Vector2<float> direction;
public:
    static const float OPENING_ANGLE;
    static const float MAX_FOOD;
    const static float MAX_DISTANCE_VIEW_FOOD;
    const static float MIN_DISTANCE_VIEW_FOOD;
public:
    const Vector2<float> &getDirection() const;

public:
    AntBase(Environment *environment, Anthill *parentAnthill, float life = MathUtils::random(1000, 2500),
            float speed = 1);

    void update() override;

    /**
     * Indique si la fourmis transporte de la nourriture
     * @return true si la fourmis transporte de la nourriture
     */
    bool hasFood() const;

    /**
     * Récupère de la nourriture
     * @param amount la quantité à récupérer
     * @pre amount <= 5
     */
    void grabFood(float amount);

    /**
     * Depose toute sa nourriture
     */
    float dropFood();

    /**
     * Effectuer une rotation d'un angle en radian
     * @param angle un angle en radian
     */
    void rotate(float angle);

    /**
     * Faire demi-tour
     */
    void turnAround();

    /**
     * Oriente la fourmis vers une cible
     * @param target la cible
     */
    void rotateToTarget(const Vector2<float> &target);

    /**
     * Déplace la fourmis
     */
    void move();
};


#endif //ANTS_ANTBASE_H
