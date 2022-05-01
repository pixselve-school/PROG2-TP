//
// Created by Mael Kerichard on 10/04/2022.
//

#include "OrRule.h"

bool OrRule::condition() {
    return condition1->condition() || condition2->condition();
}

void OrRule::action() {
    if (condition1->condition()) {
        condition1->action();
    } else if (condition2->condition()) {
        condition2->action();
    }
}

OrRule::OrRule(AbstractRule *condition1, AbstractRule *condition2) : condition1(condition1), condition2(condition2) {}
