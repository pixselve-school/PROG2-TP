//
// Created by Mael Kerichard on 08/05/2022.
//

#ifndef MIXAGE_FILTRE_COMPOSE_H
#define MIXAGE_FILTRE_COMPOSE_H

#include <map>
#include "filtre_base.h"

class filtre_compose : public filtre_base {
private:
    std::vector<std::shared_ptr<composant>> _components;
    /**
     * Associe un index d'entrée avec (indice entrée du composant, composant visé)
     */
    std::map<unsigned int, std::pair<unsigned int, std::shared_ptr<filtre>>> _links;
public:
    filtre_compose(const unsigned int outputCount, const unsigned int inputCount) : filtre_base(outputCount,
                                                                                                inputCount) {}

    void connecterEntree(const std::shared_ptr<flot> &f, unsigned int numentree) override {
        consommateur_base::connecterEntree(f, numentree);
        // check if a link exists
        if (_links.find(numentree) != _links.end()) {
            auto link = _links.at(numentree);
            link.second->connecterEntree(consommateur_base::getEntree(numentree), link.first);
        }
    }

    void calculer() override {
        for (auto &item: _components) {
            item->calculer();
        }
    }

    void addComponent(const std::shared_ptr<composant> &composant_item) {
        _components.push_back(composant_item);
    }

    void makeLink(const unsigned int inputIndex, const std::shared_ptr<filtre>& component,
                  const unsigned int componentInputIndex) {
        _links.insert({inputIndex, {componentInputIndex, component}});
    }

};


#endif //MIXAGE_FILTRE_COMPOSE_H
