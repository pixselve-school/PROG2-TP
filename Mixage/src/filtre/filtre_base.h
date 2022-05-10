//
// Created by mkerichard on 04/05/22.
//

#ifndef MIXAGE_FILTRE_BASE_H
#define MIXAGE_FILTRE_BASE_H


#include "../consommateur_base.h"
#include "../producteur_base.h"
#include "filtre.h"

class filtre_base : public filtre, public producteur_base, public consommateur_base {
public:
    filtre_base(const unsigned int output_count, const unsigned int input_count) : producteur_base(output_count), consommateur_base(input_count) {}

};


#endif //MIXAGE_FILTRE_BASE_H
