#include <string>
#include <utility>
#include <cassert>
#include "Chainon.h"
#include <iostream>

// interface Pile.
class PileChainon {
private:
    // attributs
    const Chainon<std::string> * element;
    size_t size;

public:
    // initialiser un pile vide de capacité prédéfinie
    PileChainon(): size(0), element(nullptr) {}

    // destructeur
    ~PileChainon() {
        while (element != nullptr) {
            pop();
        }
    }

    //------------------------------------------------------------------------
    // opérations sur la pile
    //------------------------------------------------------------------------

    // déterminer si la pile est vide
    bool empty() const {
        return size == 0;
    }

    // déterminer si la pile est pleine
    bool full() const {
        return false;
    }

    /**
     * empiler x au sommet de la pile
     * @pre : pile non pleine
     */
    void push(const std::string & valeur) {
        element = new Chainon<std::string>(valeur, element);
        size++;
    }

    /**
     * dépiler l'élément au sommet de la pile
     * @pre : pile non vide
     */
    void pop() {
        assert(!empty());
        auto temp = element->getPrevious();
        delete element;
        element = temp;
        size--;
    }

    /**
     * valeur de l'élément au sommet
     * @pre : pile non vide
     */
    const std::string & top() const {
        assert(!empty());
        return element->getValue();
    }

    // afficher le contenu de la pile
    void afficher() const {
        auto current = element;
        std::cout << "[";
        while (current != nullptr) {
            std::cout << current->getValue() << " ";
            current = current->getPrevious();
        }
        std::cout << "]";
    }
};
