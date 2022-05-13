//
// Created by Mael Kerichard on 13/05/2022.
//

#ifndef MIXAGE_VOLUME_COMPOSE_H
#define MIXAGE_VOLUME_COMPOSE_H


#include "filtre_compose.h"
#include "multiplicateur.h"
#include "volume.h"

class volume_compose : public filtre_compose {
public:
    explicit volume_compose(const double volume_value) : filtre_compose(1,
                                                               1) {
        std::shared_ptr<multiplicateur> multiplicateur_filter = std::make_shared<multiplicateur>();
        std::shared_ptr<volume> volume_filter = std::make_shared<volume>(volume_value);
        multiplicateur_filter->connecterEntree(volume_filter->getSortie(0), 0);
        makeLink(0, multiplicateur_filter, 1);
        connecterSortie(multiplicateur_filter->getSortie(0), 0);
    }
};


#endif //MIXAGE_VOLUME_COMPOSE_H
