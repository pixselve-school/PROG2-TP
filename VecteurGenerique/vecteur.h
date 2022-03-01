/** \brief Ce fichier doit contenir la déclaration de la classe vecteur
    Attention, elle ne doit contenir aucune implémentation de méthode / fonction
*/

#ifndef _VECTEUR_H
#define _VECTEUR_H

#include <cstdio>
#include <iostream>
#include <cassert>

// Déclaration de la classe vecteur
template<class T>
class Vecteur {
private :
    T *tab;
    size_t size;

    void copy(const Vecteur &vecteur) {
        this->size = vecteur.size;
        this->tab = new T[this->size];
        for (size_t i = 0; i < this->size; i++) {
            this->tab[i] = vecteur.tab[i];
        }
    }

public :
    /**
     * Constructeur
     * @param size la taille du vecteur (3 par défaut)
     * @param default_value la valeur d'initialisation des composantes (0 par défaut)
     */
    Vecteur(size_t size = 3, T default_value = T{}) : size(size), tab(new T[size]) {
        assert(size > 0);
        for (size_t i = 0; i < size; i++) {
            this->tab[i] = default_value;
        }
    }

    /**
     * Destructeur
     */
    ~Vecteur() {
        delete[] this->tab;
    }

    /**
     * Constructeur de copie
     * @param vecteur le vecteur à copier
     */
    Vecteur(const Vecteur &vecteur) : size(vecteur.size), tab(new T[vecteur.size]) {
        for (size_t i = 0; i < this->size; i++) {
            this->tab[i] = vecteur.tab[i];
        }
    }

    /**
     * Permet de connaître le nombre de dimensions du vecteur
     * @return le nombre de dimensions du vecteur
     */
    size_t dimensions() const {
        return this->size;
    }

    /**
     * Permet de consulter la valeur d'une coordonnée
     * @param i la coordonnée
     * @return la valeur de la ieme coordonnée
     */
    T get(size_t i) const {
        assert(i < this->size);
        return this->tab[i];
    }

    /**
     * Permet de changer la valeur d'une coordonnée.
     * @param i la coordonnée
     * @param value la nouvelle valeur
     */
    void set(size_t i, T value) {
        assert(i < this->size);
        this->tab[i] = value;
    }

    /**
     * Redéfinition de l’opérateur d’affectation
     * @param vecteur le vecteur à affecter
     * @return le vecteur affecté
     */
    Vecteur &operator=(const Vecteur &vecteur) {
        if (this != &vecteur) {
            this->copy(vecteur);
        }
        return *this;
    }


    /**
     * Permet de modifier la valeur d'une coordonnée
     * @param i la coordonnée
     * @return la valeur de la ieme coordonnée
     */
    T &operator[](int i) {
        assert(i < this->size);
        return this->tab[i];
    }

    /**
     * Permet de consulter la valeur d'une coordonnée
     * @param i la coordonnée
     * @return la valeur de la ieme coordonnée
     */
    const T &operator[](int i) const {
        assert(i < this->size);
        return this->tab[i];
    }

private :
    // méthodes privées d'implémentation (si besoin)
};

/**
 * Redéfinition de l’opérateur d’addition
 * @param vecteur le vecteur à ajouter
 * @return le résultat de l’addition
 */
template<class T1, class T2>
Vecteur<T1> operator+(const Vecteur<T1> &vecteur1, const Vecteur<T2> &vecteur2) {
    assert(vecteur1.dimensions() == vecteur2.dimensions());
    Vecteur<T1> result(vecteur1.dimensions());
    for (size_t i = 0; i < result.dimensions(); i++) {
        result.set(i, vecteur1.get(i) + vecteur2.get(i));
    }
    return result;
}




/**
 * Fonction qui affiche le vecteur v dans le flux de sortie out.
 * @param v le veteur à afficher
 * @param out flux de sortie out
 */
template<class T>
void afficherVecteur(const Vecteur<T> *v, std::ostream &out = std::cout) {
    out << "[";
    for (size_t i = 0; i < v->dimensions(); i++) {
        out << v->get(i);
        if (i != v->dimensions() - 1) {
            out << ", ";
        }
    }
    out << "]";
}


/**
 * Fonction qui crée et initialise un vecteur dont les caractéristiques (nombres de dimensions et valeur de chaque coordonnée) sont fournies par l'utilisateur sur le flux d'entrée in.
 * @param in flux d'entrée in
 * @return le vecteur initialisé
 */
template<class T>
Vecteur<T> *lireVecteur(std::istream &in = std::cin) {
    size_t size;
    in >> size;
    auto *v = new Vecteur<T>(size);
    for (size_t i = 0; i < size; i++) {
        T value;
        in >> value;
        v->set(i, value);
    }
    return v;
}

/**
 * Additionner deux vecteurs
 * @param v1 un vecteur
 * @param v2 un vecteur
 * @return un vecteur résultant de l'addition de v1 et v2
 */
template<class T>
Vecteur<T> add(const Vecteur<T> *v1, const Vecteur<T> *v2) {
    assert(v1->dimensions() == v2->dimensions());
    Vecteur<T> result(v1->dimensions());
    for (size_t i = 0; i < v1->dimensions(); i++) {
        result.set(i, v1->get(i) + v2->get(i));
    }
    return result;
}

/**
 * Produit scalaire
 * @param vecteur le vecteur à multiplier
 * @return le résultat du produit scalaire
 */
template<class T1, class T2>
float operator*(const Vecteur<T1> &vecteur1, const Vecteur<T2> &vecteur2) {
    float result = 0;
    for (int i = 0; i < vecteur1.dimensions(); i++) {
        result += vecteur1.get(i) * vecteur2.get(i);
    }
    return result;
}

/**
 * Affichage d'un vecteur
 * @param out flux de sortie
 * @param vecteur le vecteur à afficher
 * @return le flux de sortie
 */
template<class T>
std::ostream &operator<<(std::ostream &out, const Vecteur<T> &vecteur) {
    afficherVecteur(&vecteur, out);
    return out;
}

/**
 * Lecture d'un vecteur
 * @param in flux d'entrée
 * @param vecteur le vecteur à lire
 * @return le flux d'entrée
 */
template<class T>
std::istream &operator>>(std::istream &in, Vecteur<T> &vecteur) {
    for (int i = 0; i < vecteur.dimensions(); ++i) {
        T value;
        in >> value;
        vecteur.set(i, value);
    }
    return in;
}


#endif