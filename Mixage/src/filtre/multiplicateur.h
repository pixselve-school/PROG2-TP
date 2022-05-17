//
// Created by mkerichard on 04/05/22.
//

#ifndef MIXAGE_MULTIPLICATEUR_H
#define MIXAGE_MULTIPLICATEUR_H


#include "filtre.h"
#include "filtre_base.h"

class multiplicateur : public filtre_base {
private:

public:
    explicit multiplicateur() : filtre_base(1, 2) {}

    void calculer() override {
        assert(yaDesEchantillons());
        double result = getEntree(0)->extraire() * getEntree(1)->extraire();
        getSortie(0)->inserer(result);
    }
};


#endif //MIXAGE_MULTIPLICATEUR_H
