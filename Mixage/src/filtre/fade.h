//
// Created by Mael Kerichard on 15/05/2022.
//

#ifndef MIXAGE_FADE_H
#define MIXAGE_FADE_H


#include "filtre_base.h"
#include "volume.h"
#include "constantes.h"

class fade : public filtre_base {
private:
    double _current_time;
    double _duration;
    double _start;
    double _volume_from;
    double _current_volume;
    double _step;

public:
    explicit fade(const double start, const double duration, const double volume_from, const double volume_to)
            : filtre_base(1, 1), _current_time(0), _duration(duration), _start(start), _volume_from(volume_from),
               _step((volume_to - volume_from) / duration), _current_volume(volume_from) {
    }

public:
    unsigned int nbEntrees() const override {
        return consommateur_base::nbEntrees();
    }

    const std::shared_ptr<flot> &getEntree(unsigned int numentree) const override {
        return consommateur_base::getEntree(numentree);
    }

    void connecterEntree(const std::shared_ptr<flot> &f, unsigned int numentree) override {
        consommateur_base::connecterEntree(f, numentree);
    }

    bool yaDesEchantillons() const override {
        return consommateur_base::yaDesEchantillons();
    }

    unsigned int nbSorties() const override {
        return producteur_base::nbSorties();
    }

    const std::shared_ptr<flot> &getSortie(unsigned int numsortie) const override {
        return producteur_base::getSortie(numsortie);
    }

    void calculer() override {
        assert(consommateur_base::yaDesEchantillons());
        auto result = consommateur_base::getEntree(0)->extraire();
        if (_current_time > _start && _current_time < _start + _duration) {
            _current_volume = _volume_from + _step * (_current_time - _start);
        }
        result *= _current_volume;
        _current_time += 1.0 / MixageSonore::frequency;
        producteur_base::getSortie(0)->inserer(result);
    }

};


#endif //MIXAGE_FADE_H
