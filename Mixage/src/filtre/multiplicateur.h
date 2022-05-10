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
    multiplicateur() : filtre_base(1, 2) {}

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

    const std::shared_ptr<flot> &getSortie(unsigned int numsortie) const override {
        return producteur_base::getSortie(numsortie);
    }

    void calculer() override {
        assert(yaDesEchantillons());
        double result = getEntree(0)->extraire() * getEntree(1)->extraire();
        getSortie(0)->inserer(result);
    }

    unsigned int nbSorties() const override {
        return producteur_base::nbSorties();
    }
};


#endif //MIXAGE_MULTIPLICATEUR_H
