#include <string>
#include <cassert>
#include <iostream>

// interface Pile.
class PileC {
private:
    // attributs
    std::string * m_elements;
//    size_t m_size;
    size_t m_max_size;
    std::string * m_top;

public:
    // initialiser un pile vide de capacité prédéfinie
    explicit PileC(size_t max_size = 10): m_max_size(max_size), m_elements(new std::string[max_size]), m_top(m_elements)  {

    }

    // destructeur
    ~PileC() {
        delete[] m_elements;
    }

    //------------------------------------------------------------------------
    // opérations sur la pile
    //------------------------------------------------------------------------

    // déterminer si la pile est vide
    bool empty() const {
        return m_top == m_elements + m_max_size;
    }

    // déterminer si la pile est pleine
    bool full() const {
        return m_top == m_elements + m_max_size;
    }

    /**
     * empiler x au sommet de la pile
     * @pre : pile non pleine
     */
    void push(const std::string & valeur) {
        *m_top = valeur;
        m_top++;
    }

    /**
     * dépiler l'élément au sommet de la pile
     * @pre : pile non vide
     */
    void pop() {
        m_top--;
    }

    /**
     * valeur de l'élément au sommet
     * @pre : pile non vide
     */
    const std::string & top() const {
        return *m_top;
    }

    // afficher le contenu de la pile
    void afficher() const {
        for (size_t i = m_max_size; i >= 0; i--) {
            std::cout << m_elements[i] << std::endl;
        }
    }
};
