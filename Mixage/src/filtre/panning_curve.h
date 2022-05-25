//
// Created by Mael Kerichard on 25/05/2022.
//

#ifndef MIXAGE_PANNING_CURVE_H
#define MIXAGE_PANNING_CURVE_H


#include "filtre_base.h"

class panning_curve : public filtre_base {
public:
    panning_curve() : filtre_base(2,
                                  1) {}

public:
    void calculer() override {
        assert(filtre_base::yaDesEchantillons());
        auto curve = filtre_base::getEntree(0)->extraire();
        auto sound_on_first = (curve + 1) / 2;
        auto sound_on_second = 1 - sound_on_first;
        filtre_base::getSortie(0)->inserer(sound_on_first);
        filtre_base::getSortie(1)->inserer(sound_on_second);
    }
};


#endif //MIXAGE_PANNING_CURVE_H
