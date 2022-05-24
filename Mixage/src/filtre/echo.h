//
// Created by Mael Kerichard on 22/05/2022.
//

#ifndef MIXAGE_ECHO_H
#define MIXAGE_ECHO_H


#include "filtre_base.h"
#include "duplicate.h"
#include "filtre_compose.h"
#include "delay.h"
#include "adder.h"
#include "volume.h"
#include <queue>

/**
 * Echo filter
 */
class echo : public filtre_compose {
public:
    explicit echo(double delay_value, double attenuation) : filtre_compose(1, 1) {
        auto duplicate_filter = std::make_shared<duplicate>();
        auto delay_filter = std::make_shared<delay>(delay_value);
        auto volume_filter = std::make_shared<volume>(attenuation);
        auto adder_filter = std::make_shared<adder>(2);
        // add the components
        addComponent(duplicate_filter);
        addComponent(delay_filter);
        addComponent(volume_filter);
        addComponent(adder_filter);

        // connect the input\outputs
        makeInputLink(0, duplicate_filter, 0);
        makeOutputLink(0, adder_filter, 0);

        // make internal connections
        delay_filter->connecterEntree(duplicate_filter->getSortie(0), 0);
        volume_filter->connecterEntree(delay_filter->getSortie(0), 0);
        adder_filter->connecterEntree(volume_filter->getSortie(0), 0);
        adder_filter->connecterEntree(duplicate_filter->getSortie(1), 1);
    }
};


#endif //MIXAGE_ECHO_H
