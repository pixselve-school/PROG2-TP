//
// Created by mkerichard on 04/05/22.
//

#ifndef MIXAGE_PRODUCTEUR_BASE_H
#define MIXAGE_PRODUCTEUR_BASE_H


#include <vector>
#include "producteur.h"
#include "imp_flot.h"

class producteur_base : public producteur {
private:
    std::vector<std::shared_ptr<flot>> _outputs;
public:
    explicit producteur_base(const unsigned int output_count) : _outputs(output_count, std::make_shared<imp_flot>()) {}

public:
protected:
    void connecterSortie(const std::shared_ptr<flot> &f, unsigned int outputIndex) {
        _outputs.at(outputIndex) = f;
    }

public:
    unsigned int nbSorties() const override {
        return _outputs.size();
    }

    const std::shared_ptr<flot> &getSortie(unsigned int numsortie) const override {
        return _outputs.at(numsortie);
    }

    ~producteur_base() override = default;
};


#endif //MIXAGE_PRODUCTEUR_BASE_H
