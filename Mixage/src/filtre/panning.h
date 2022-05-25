//
// Created by Mael Kerichard on 24/05/2022.
//

#ifndef MIXAGE_PANNING_H
#define MIXAGE_PANNING_H


#include "filtre_compose.h"
#include "volume.h"
#include "panning_curve.h"

class panning : public filtre_compose {
public:
    explicit panning() : filtre_compose(2, 3) {
        auto panning_curve_filter = std::make_shared<panning_curve>();
        auto multiplier_left = std::make_shared<multiplicateur>();
        auto multiplier_right = std::make_shared<multiplicateur>();
        addComponent(panning_curve_filter);
        addComponent(multiplier_left);
        addComponent(multiplier_right);

        makeInputLink(0, multiplier_left, 0);
        makeInputLink(1, multiplier_right, 0);
        makeInputLink(2, panning_curve_filter, 0);

        multiplier_left->connecterEntree(panning_curve_filter->getSortie(0), 1);
        multiplier_right->connecterEntree(panning_curve_filter->getSortie(1), 1);

        makeOutputLink(0, multiplier_left, 0);
        makeOutputLink(1, multiplier_right, 0);
    }
};


#endif //MIXAGE_PANNING_H
