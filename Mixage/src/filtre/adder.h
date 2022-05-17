//
// Created by Mael Kerichard on 11/05/2022.
//

#ifndef MIXAGE_ADDER_H
#define MIXAGE_ADDER_H


#include "filtre_compose.h"

class adder : public filtre_base {
public:
    explicit adder(const unsigned int inputCount) : filtre_base(1, inputCount) {}

    void calculer() override {
        assert(filtre_base::yaDesEchantillons());
        double result = 0;
        for (int i = 0; i < filtre_base::nbEntrees(); ++i) {
            result += filtre_base::getEntree(i)->extraire();
        }
        filtre_base::getSortie(0)->inserer(result);
    }
};


#endif //MIXAGE_ADDER_H
