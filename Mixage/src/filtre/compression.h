//
// Created by Mael Kerichard on 15/05/2022.
//

#ifndef MIXAGE_COMPRESSION_H
#define MIXAGE_COMPRESSION_H


#include <valarray>
#include "filtre_base.h"

class compression : public filtre_base {
private:
    const double _strength;
public:
    explicit compression(const double strength) : filtre_base(1, 1), _strength(strength) {
        assert(strength >= 0 && strength < 1);
    }

    static double signe(const double x) {
        return (x >= 0) ? 1 : -1;
    }

    void calculer() override {
        auto signal = consommateur_base::getEntree(0)->extraire();
        producteur_base::getSortie(0)->inserer(signe(signal) * pow(std::abs(signal), _strength));
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


#endif //MIXAGE_COMPRESSION_H
