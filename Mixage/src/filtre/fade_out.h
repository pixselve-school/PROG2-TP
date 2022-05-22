//
// Created by Mael Kerichard on 15/05/2022.
//

#ifndef MIXAGE_FADE_OUT_H
#define MIXAGE_FADE_OUT_H


#include "filtre_compose.h"
#include "fade.h"

class fade_out : public filtre_compose {
public:
    /**
     * @param duration the duration of the fade in (in seconds)
     * @param start the start of the fade in (in seconds)
     */
    explicit fade_out(const int duration, const int start) : filtre_compose(1, 1) {
        auto fade_filter = std::make_shared<fade>(start, duration, 1, 0);
        addComponent(fade_filter);
        makeInputLink(0, fade_filter, 0);
        makeOutputLink(0, fade_filter, 0);
    }
};


#endif //MIXAGE_FADE_OUT_H
