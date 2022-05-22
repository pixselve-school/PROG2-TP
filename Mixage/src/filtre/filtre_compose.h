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
        filtre_base::connecterEntree(f, numentree);
        // check if a link exists
        if (_links.find(numentree) != _links.end()) {
            auto link = _links.at(numentree);
            link.second->connecterEntree(filtre_base::getEntree(numentree), link.first);
        }
    }

    void calculer() override {
        for (auto &item: _components) {
            item->calculer();
        }
    }

    /**
     * Add an internal component
     * @param composant_item the component to add
     */
    void addComponent(const std::shared_ptr<composant> &composant_item) {
        _components.push_back(composant_item);
    }

    /**
     * Make a link from a filter input to a internal component's input
     * @param input_index the filter input index
     * @param component the component
     * @param component_input_index the component input index
     */
    void makeInputLink(const unsigned int input_index, const std::shared_ptr<filtre> &component,
                       const unsigned int component_input_index) {
        _links.insert({input_index, {component_input_index, component}});

    }

    /**
     * Make a link from a internal component's output to a filter output
     * @param output_index the filter output index
     * @param component the component
     * @param component_output_index the component output index
     */
    void makeOutputLink(const unsigned int output_index, const std::shared_ptr<filtre> &component,
                        const unsigned int component_output_index) {
        connecterSortie(component->getSortie(component_output_index), output_index);

    }


};


#endif //MIXAGE_FILTRE_COMPOSE_H
