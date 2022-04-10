//
// Created by Mael Kerichard on 10/04/2022.
//

#ifndef ANTS_SILLYANT_H
#define ANTS_SILLYANT_H


#include "AntBase.h"

class SillyAnt : public AntBase {
public:
    SillyAnt(Environment *environment, Anthill *parentAnthill);

    void update() override;
};


#endif //ANTS_SILLYANT_H
