//
// Created by Mael Kerichard on 10/04/2022.
//

#ifndef ANTS_ANTWITHRULES_H
#define ANTS_ANTWITHRULES_H


#include "AntBasePheromone.h"
#include "../rules/AbstractAntRule.h"
#include "memory"

class AntOnFood : public AbstractAntRule {
public:
    explicit AntOnFood(AntBasePheromone *targetAnt);

private:
    bool condition() override;

    void action() override;
};

class AntAtHome : public AbstractAntRule {
public:
    explicit AntAtHome(AntBasePheromone *targetAnt);

private:
    bool condition() override;

    void action() override;
};

class AntSniffPheromonesToHome : public AbstractAntRule {
public:
    explicit AntSniffPheromonesToHome(AntBasePheromone *targetAnt);

public:
    bool condition() override;

    void action() override;
};

class GoToHome : public AbstractAntRule {
public:
    explicit GoToHome(AntBasePheromone *targetAnt);

    bool condition() override;

    void action() override;
};

class AntSeesFood : public AbstractAntRule {
public:
    explicit AntSeesFood(AntBasePheromone *targetAnt);

private:
    bool condition() override;

    void action() override;
};

class AntSniffPheromone : public AbstractAntRule {
public:
    explicit AntSniffPheromone(AntBasePheromone *targetAnt);

private:
    bool condition() override;

    void action() override;
};

class AntBaseAction : public AbstractAntRule {
public:
    explicit AntBaseAction(AntBasePheromone *targetAnt);

private:
    bool condition() override;

    void action() override;
};

class AntWithRules : public AntBasePheromone {
private:
    std::unique_ptr<AbstractRule> ruleWhenCarryingFood;
    std::unique_ptr<AbstractRule> ruleWhenSearching;
public:
    AntWithRules(Environment *environment, Anthill *parentAnthill);

    void update() override;

    ~AntWithRules() override;
};


#endif //ANTS_ANTWITHRULES_H
