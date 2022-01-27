#include <string>

// interface Pile.
class Pile {
private:
    // attributs
    std::string * m_elements;
//    size_t m_size;
    size_t m_max_size;
    std::string * m_top;

public:
    // initialiser un pile vide de capacité prédéfinie
    Pile();

    // destructeur
    ~Pile();

    //------------------------------------------------------------------------
    // opérations sur la pile
    //------------------------------------------------------------------------

    // déterminer si la pile est vide
    bool empty() const;

    // déterminer si la pile est pleine
    bool full() const;

    /**
     * empiler x au sommet de la pile
     * @pre : pile non pleine
     */
    void push(std::string valeur);

    /**
     * dépiler l'élément au sommet de la pile
     * @pre : pile non vide
     */
    void pop();

    /**
     * valeur de l'élément au sommet
     * @pre : pile non vide
     */
    std::string top() const;

    // afficher le contenu de la pile
    void afficher() const;
};
