//
// Created by Mael Kerichard on 10/04/2022.
//

#ifndef ANTS_ABSTRACTRULE_H
#define ANTS_ABSTRACTRULE_H


class AbstractRule {
public:
    virtual bool condition() = 0;

    virtual void action() = 0;

    virtual ~AbstractRule() = default;
};


#endif //ANTS_ABSTRACTRULE_H
