//
// Created by Mael Kerichard on 22/05/2022.
//

#ifndef MIXAGE_DELAY_H
#define MIXAGE_DELAY_H


#include "filtre_base.h"
#include "constantes.h"

/**
 * Apply a delay from the input to the output
 * @note if current time < delay, we output 0
 */
class delay : public filtre_base {
private:
    double _current_time;
    double _delay_value;
    std::shared_ptr<flot> _buffer;

public:
    /**
     * Create a delay filter
     * @param delay_value the delay value
     */
    explicit delay(const double delay_value) : filtre_base(1, 1), _delay_value(delay_value), _current_time(0),
                                               _buffer(std::make_shared<imp_flot>()) {}

    void calculer() override {
        assert(filtre_base::yaDesEchantillons());
        // increment current time
        _current_time += 1.0 / MixageSonore::frequency;
        // if current time is greater than delay value, we can output the sample on the input, else we output 0
        _buffer->inserer(filtre_base::getEntree(0)->extraire());
        filtre_base::getSortie(0)->inserer(_current_time > _delay_value ? _buffer->extraire() : 0);
    }

};


#endif //MIXAGE_DELAY_H
