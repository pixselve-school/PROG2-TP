//
// Created by mkerichard on 04/05/22.
//

#ifndef MIXAGE_SIGNAL_CONSTANT_H
#define MIXAGE_SIGNAL_CONSTANT_H


#include "producteur.h"
#include "imp_flot.h"
#include "cassert"

class signal_constant : private producteur {
private:
    std::shared_ptr<flot> signal;
    double signal_value;
public:
    explicit signal_constant(const double signal_value) : signal_value(signal_value),
                                                          signal(std::make_shared<imp_flot>()) {
    };

    signal_constant &operator=(const signal_constant &) = default;

    void calculer() override {
        signal->inserer(signal_value);
    };

    unsigned int nbSorties() const override {
        return 1;
    };

    const std::shared_ptr<flot> &getSortie(unsigned int numsortie) const override {
        assert(numsortie >= 0 && numsortie < nbSorties());
        return signal;
    };

};


#endif //MIXAGE_SIGNAL_CONSTANT_H
