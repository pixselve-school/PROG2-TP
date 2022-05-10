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
    unsigned int nbEntrees() const override {
        return consommateur_base::nbEntrees();
    }

    const std::shared_ptr<flot> &getEntree(unsigned int numentree) const override {
        return consommateur_base::getEntree(numentree);
    }

    void connecterEntree(const std::shared_ptr<flot> &f, unsigned int numentree) override {
        consommateur_base::connecterEntree(f, numentree);
    }

    bool yaDesEchantillons() const override {
        return consommateur_base::yaDesEchantillons();
    }

    unsigned int nbSorties() const override {
        return producteur_base::nbSorties();
    }

    const std::shared_ptr<flot> &getSortie(unsigned int numsortie) const override {
        return producteur_base::getSortie(numsortie);
    }

public:
    void calculer() override {
        assert(yaDesEchantillons());
        T operation;
        double result = operation(getEntree(0)->extraire(), getEntree(1)->extraire());
        getSortie(0)->inserer(result);
    }

};


#endif //MIXAGE_OPERATION_BINAIRE_H
