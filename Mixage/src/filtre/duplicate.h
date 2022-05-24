//
// Created by Mael Kerichard on 22/05/2022.
//

#ifndef MIXAGE_DUPLICATE_H
#define MIXAGE_DUPLICATE_H


#include <queue>
#include "filtre_base.h"

/**
 * Duplicate input into two outputs
 */
class duplicate : public filtre_base {
public:
    duplicate() : filtre_base(2, 1) {}

    void calculer() override {
        assert(filtre_base::yaDesEchantillons());
        double flot_value = filtre_base::getEntree(0)->extraire();
        filtre_base::getSortie(0)->inserer(flot_value);
        filtre_base::getSortie(1)->inserer(flot_value);
    }
};


#endif //MIXAGE_DUPLICATE_H
