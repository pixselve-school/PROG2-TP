//
// Created by mkerichard on 04/05/22.
//

#ifndef MIXAGE_HARMONIQUE_H
#define MIXAGE_HARMONIQUE_H


#include "producteur_base.h"
#include "constantes.h"
#include <cmath>

class harmonique : public producteur_base {
private:
    const int frequency;
    const double phase;
    unsigned int i;
public:
    void calculer() override {
        i++;
        producteur_base::getSortie(0)->inserer(generate_wave());
    }

public:
    harmonique(const int frequency, const double phase) : frequency(frequency), phase(phase), i(0),
                                                          producteur_base(1) {}

private:
    double generate_wave() const {
        return sin(((double) i / MixageSonore::frequency) * 2 * MixageSonore::pi * frequency + phase);
    }
};


#endif //MIXAGE_HARMONIQUE_H
