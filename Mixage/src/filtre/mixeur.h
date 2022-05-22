//
// Created by Mael Kerichard on 11/05/2022.
//

#ifndef MIXAGE_MIXEUR_H
#define MIXAGE_MIXEUR_H


#include "filtre_compose.h"
#include "volume.h"
#include "adder.h"

class mixeur : public filtre_compose {
public:
    explicit mixeur(const std::vector<double> &volumes) : filtre_compose(1, volumes.size()) {
        std::shared_ptr<adder> adder_filter = std::make_shared<adder>(volumes.size());
        for (int i = 0; i < volumes.size(); ++i) {
            const auto &volume_item = volumes.at(i);
            std::shared_ptr<volume> volume_filter = std::make_shared<volume>(volume_item);
            makeInputLink(i, volume_filter, 0);
            adder_filter->connecterEntree(volume_filter->getSortie(0), i);
            addComponent(volume_filter);
        }
        makeOutputLink(0, adder_filter, 0);
        addComponent(adder_filter);
    }
};


#endif //MIXAGE_MIXEUR_H
