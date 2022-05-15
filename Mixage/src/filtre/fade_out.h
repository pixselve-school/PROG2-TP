//
// Created by Mael Kerichard on 15/05/2022.
//

#ifndef MIXAGE_FADE_OUT_H
#define MIXAGE_FADE_OUT_H


#include "filtre_compose.h"
#include "fade.h"

class fade_out: public filtre_compose {
public:
    /**
     * @param duration the duration of the fade in (in seconds)
     * @param start the start of the fade in (in seconds)
     */
    explicit fade_out(const int duration, const int start) : filtre_compose(1, 1) {
        auto fade_filter = std::make_shared<fade>(start, duration, 1, 0);
        makeLink(0, fade_filter, 0);
        connecterSortie(fade_filter->getSortie(0), 0);
        addComponent(fade_filter);
    }

    unsigned int nbEntrees() const override {
        return consommateur_base::nbEntrees();
    }

    const std::shared_ptr<flot> &getEntree(unsigned int numentree) const override {
        return consommateur_base::getEntree(numentree);
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


#endif //MIXAGE_FADE_OUT_H
