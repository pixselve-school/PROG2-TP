//
// Created by Mael Kerichard on 10/04/2022.
//

#ifndef ANTS_ORRULE_H
#define ANTS_ORRULE_H

#include <memory>
#include "AbstractRule.h"

class OrRule : public AbstractRule {
    std::unique_ptr<AbstractRule> condition1;
    std::unique_ptr<AbstractRule> condition2;
public:
    OrRule(AbstractRule *condition1, AbstractRule *condition2);

public:
    bool condition() override;

    void action() override;

};


#endif //ANTS_ORRULE_H
