//
// Created by Mael Kerichard on 08/05/2022.
//

#ifndef MIXAGE_OPERATION_BINAIRE_H
#define MIXAGE_OPERATION_BINAIRE_H

#include "filtre_base.h"
#include "functional"

template<class T>
class operation_binaire : public filtre_base {
public:
    operation_binaire() : filtre_base(1,
                                      2) {}
public:
    void calculer() override {
        assert(yaDesEchantillons());
        T operation;
        double result = operation(getEntree(0)->extraire(), getEntree(1)->extraire());
        getSortie(0)->inserer(result);
    }

};


#endif //MIXAGE_OPERATION_BINAIRE_H
