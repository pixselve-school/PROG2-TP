//
// Created by mkerichard on 04/05/22.
//

#ifndef MIXAGE_IMP_FLOT_H
#define MIXAGE_IMP_FLOT_H


#include <deque>
#include "flot.h"
#include "cassert"

class imp_flot: public flot {
public:
    void inserer(double echantillon) override {
        samples.push_back(echantillon);
    };

    double extraire() override {
        assert(!vide());
        auto front = samples.front();
        samples.pop_front();
        return front;
    };

    bool vide() const override {
        return samples.empty();
    };

private:
    std::deque<double> samples;
};


#endif //MIXAGE_IMP_FLOT_H
