//
// Created by Mael Kerichard on 10/04/2022.
//

#include "AntWithRules.h"

#include <memory>
#include "../ant-environment/Food.h"
#include "../utils/Timer.h"
#include "../rules/OrRule.h"

bool AntOnFood::condition() {
    if (getTargetAnt()->hasFood()) return false;
    auto foodOnAnt = getTargetAnt()->perceive<Food>();
    return !foodOnAnt.empty();
}

void AntOnFood::action() {
    auto ant = getTargetAnt();
    auto foodOnAnt = ant->perceive<Food>().front();
    ant->grabFood(foodOnAnt->collectFood(AntBase::MAX_FOOD));
    ant->rotateToTarget(ant->getParentAnthill()->getPosition());
}

AntOnFood::AntOnFood(AntBasePheromone *targetAnt) : AbstractAntRule(targetAnt) {}

bool AntAtHome::condition() {
    if (!getTargetAnt()->hasFood()) return false;
    auto anthillOnAnt = getTargetAnt()->perceive<Anthill>();
    if (anthillOnAnt.empty()) {
        return false;
    }
    return anthillOnAnt.front() == getTargetAnt()->getParentAnthill();
}

void AntAtHome::action() {
    auto ant = getTargetAnt();
    ant->getParentAnthill()->depositFood(ant->dropFood());
    ant->turnAround();
}

AntAtHome::AntAtHome(AntBasePheromone *targetAnt) : AbstractAntRule(targetAnt) {}

bool AntSeesFood::condition() {
    auto foodInView = getTargetAnt()->perceive<Food>(getTargetAnt()->getDirection(), AntBase::OPENING_ANGLE,
                                                     AntBase::MAX_DISTANCE_VIEW_FOOD, AntBasePheromone::MIN_DISTANCE_VIEW_FOOD);
    return !foodInView.empty();
}

void AntSeesFood::action() {
    auto ant = getTargetAnt();
    auto foodInView = ant->perceive<Food>(ant->getDirection(), AntBase::OPENING_ANGLE,
                                          AntBase::MAX_DISTANCE_VIEW_FOOD, AntBasePheromone::MIN_DISTANCE_VIEW_FOOD).front();
    ant->rotateToTarget(foodInView->getPosition());
    ant->move();
}

AntSeesFood::AntSeesFood(AntBasePheromone *targetAnt) : AbstractAntRule(targetAnt) {}

bool AntSniffPheromone::condition() {
    auto pheromones = getTargetAnt()->choosePheromone();
    return pheromones != nullptr;
}

void AntSniffPheromone::action() {
    auto ant = getTargetAnt();
    auto pheromones = ant->choosePheromone();
    ant->rotateToTarget(pheromones->getPosition());
    ant->move();
}

AntSniffPheromone::AntSniffPheromone(AntBasePheromone *targetAnt) : AbstractAntRule(targetAnt) {}

bool AntBaseAction::condition() {
    return true;
}

void AntBaseAction::action() {
    auto angle = MathUtils::random((-MathUtils::pi / 10) * Timer::dt(),
                                   (MathUtils::pi / 10) * Timer::dt());
    getTargetAnt()->rotate(angle);
    getTargetAnt()->move();

}

AntBaseAction::AntBaseAction(AntBasePheromone *targetAnt) : AbstractAntRule(targetAnt) {}


AntWithRules::AntWithRules(Environment *environment, Anthill *parentAnthill) : ruleWhenSearching(
        std::make_unique<OrRule>(new AntOnFood(this), new OrRule(new AntSeesFood(this),
                                                                 new OrRule(new AntSniffPheromone(this),
                                                                            new AntBaseAction(this))))),
                                                                               ruleWhenCarryingFood(
                                                                                       std::make_unique<OrRule>(
                                                                                               new AntAtHome(
                                                                                                       this),
                                                                                               new OrRule(
                                                                                                       new AntSniffPheromonesToHome(
                                                                                                               this),
                                                                                                       new GoToHome(
                                                                                                               this)))),
                                                                               AntBasePheromone(environment,
                                                                                                parentAnthill) {

}

void AntWithRules::update() {
    AntBasePheromone::update();

    if (hasFood()) {
        ruleWhenCarryingFood->action();
    } else {
        ruleWhenSearching->action();
    }
}

AntWithRules::~AntWithRules() = default;

bool AntSniffPheromonesToHome::condition() {
    getTargetAnt()->rotateToTarget(getTargetAnt()->getParentAnthill()->getPosition());
    auto pheromones = getTargetAnt()->choosePheromone();
    return pheromones != nullptr;
}

void AntSniffPheromonesToHome::action() {
    getTargetAnt()->rotateToTarget(getTargetAnt()->getParentAnthill()->getPosition());
    auto pheromones = getTargetAnt()->choosePheromone();
    getTargetAnt()->rotateToTarget(pheromones->getPosition());
    getTargetAnt()->move();
}

AntSniffPheromonesToHome::AntSniffPheromonesToHome(AntBasePheromone *targetAnt) : AbstractAntRule(targetAnt) {}

GoToHome::GoToHome(AntBasePheromone *targetAnt) : AbstractAntRule(targetAnt) {}

bool GoToHome::condition() {
    return true;
}

void GoToHome::action() {
    getTargetAnt()->rotateToTarget(getTargetAnt()->getParentAnthill()->getPosition());
    getTargetAnt()->move();
}
