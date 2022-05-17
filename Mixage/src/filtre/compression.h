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
        auto signal = filtre_base::getEntree(0)->extraire();
        filtre_base::getSortie(0)->inserer(signe(signal) * pow(std::abs(signal), _strength));
    }
};


#endif //MIXAGE_COMPRESSION_H
