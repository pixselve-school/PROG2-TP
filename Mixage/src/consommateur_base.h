//
// Created by mkerichard on 04/05/22.
//

#ifndef MIXAGE_CONSOMMATEUR_BASE_H
#define MIXAGE_CONSOMMATEUR_BASE_H


#include "consommateur.h"
#include "vector"
#include "imp_flot.h"
#include "algorithm"

class consommateur_base : private consommateur {
public:
    explicit consommateur_base(const unsigned int input_count) : _inputs(input_count, std::make_shared<imp_flot>()) {}

private:
    std::vector<std::shared_ptr<flot>> _inputs;
public:
    unsigned int nbEntrees() const override {
        return _inputs.size();
    }


    const std::shared_ptr<flot> &getEntree(unsigned int numentree) const override {
        return _inputs.at(numentree);
    }

    void connecterEntree(const std::shared_ptr<flot> &f, unsigned int numentree) override {
        _inputs.at(numentree) = f;
    }

    bool yaDesEchantillons() const override {
        return std::all_of(_inputs.begin(), _inputs.end(), [](const std::shared_ptr<flot> &f) { return !f->vide(); });
    }

    ~consommateur_base() override = default;

};


#endif //MIXAGE_CONSOMMATEUR_BASE_H
