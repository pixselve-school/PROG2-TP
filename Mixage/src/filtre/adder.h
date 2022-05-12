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
        assert(consommateur_base::yaDesEchantillons());
        double result = 0;
        for (int i = 0; i < consommateur_base::nbEntrees(); ++i) {
            result += consommateur_base::getEntree(i)->extraire();
        }
        producteur_base::getSortie(0)->inserer(result);
    }

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
};


#endif //MIXAGE_ADDER_H
