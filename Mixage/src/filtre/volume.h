//
// Created by Mael Kerichard on 08/05/2022.
//

#ifndef MIXAGE_VOLUME_H
#define MIXAGE_VOLUME_H


#include "filtre_base.h"
#include "operation_binaire.h"
#include "multiplicateur.h"
#include "../signal_constant.h"

class volume : public filtre_base {
public:
    explicit volume(const double volume) : filtre_base(
            1, 1), _multiplicateur(), _signal_constant(volume) {
        _multiplicateur.connecterEntree(_signal_constant.getSortie(0), 0);
    }

    unsigned int nbEntrees() const override {
        return consommateur_base::nbEntrees();
    }

    const std::shared_ptr<flot> &getEntree(unsigned int numentree) const override {
        return consommateur_base::getEntree(numentree);
    }

    void connecterEntree(const std::shared_ptr<flot> &f, unsigned int numentree) override {
        consommateur_base::connecterEntree(f, numentree);
        _multiplicateur.connecterEntree(getEntree(0), 1);
    }

    bool yaDesEchantillons() const override {
        return consommateur_base::yaDesEchantillons();
    }

    unsigned int nbSorties() const override {
        return producteur_base::nbSorties();
    }

    const std::shared_ptr<flot> &getSortie(unsigned int numsortie) const override {
        return _multiplicateur.getSortie(0);
    }

    void change_volume(const double new_value) {
        _signal_constant = signal_constant(new_value);
    }

    void calculer() override {
        assert(yaDesEchantillons());
        _signal_constant.calculer();
        _multiplicateur.calculer();
    }

private:
    multiplicateur _multiplicateur;
    signal_constant _signal_constant;
};


#endif //MIXAGE_VOLUME_H
