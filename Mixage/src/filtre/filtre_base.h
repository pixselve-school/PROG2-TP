//
// Created by mkerichard on 04/05/22.
//

#ifndef MIXAGE_FILTRE_BASE_H
#define MIXAGE_FILTRE_BASE_H


#include "../consommateur_base.h"
#include "../producteur_base.h"
#include "filtre.h"

class filtre_base : public producteur_base, public consommateur_base, public filtre {
public:
    filtre_base(const unsigned int output_count, const unsigned int input_count) : producteur_base(output_count),
                                                                                   consommateur_base(input_count) {}

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

    ~filtre_base() override = default;
};


#endif //MIXAGE_FILTRE_BASE_H
