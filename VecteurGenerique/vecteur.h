/** \brief Ce fichier doit contenir la déclaration de la classe vecteur
    Attention, elle ne doit contenir aucune implémentation de méthode / fonction
*/

#ifndef _VECTEUR_H
#define _VECTEUR_H

#include <cstdio>

// Déclaration de la classe vecteur
class Vecteur {
private :
    float *tab;
    size_t size;

    void copy(const Vecteur &vecteur);

public :
    /**
     * Constructeur
     * @param size la taille du vecteur (3 par défaut)
     * @param default_value la valeur d'initialisation des composantes (0 par défaut)
     */
    explicit Vecteur(size_t size = 3, float default_value = 0.0);

    /**
     * Destructeur
     */
    ~Vecteur();

    /**
     * Constructeur de copie
     * @param vecteur le vecteur à copier
     */
    Vecteur(const Vecteur &vecteur);

    /**
     * Permet de connaître le nombre de dimensions du vecteur
     * @return le nombre de dimensions du vecteur
     */
    size_t dimensions() const;

    /**
     * Permet de consulter la valeur d'une coordonnée
     * @param i la coordonnée
     * @return la valeur de la ieme coordonnée
     */
    float get(size_t i) const;

    /**
     * Permet de changer la valeur d'une coordonnée.
     * @param i la coordonnée
     * @param value la nouvelle valeur
     */
    void set(size_t i, float value);

    /**
     * Redéfinition de l’opérateur d’affectation
     * @param vecteur le vecteur à affecter
     * @return le vecteur affecté
     */
    Vecteur &operator=(const Vecteur &vecteur);

    /**
     * Redéfinition de l’opérateur d’addition
     * @param vecteur le vecteur à ajouter
     * @return le résultat de l’addition
     */
    Vecteur operator+(const Vecteur &vecteur) const;


    /**
     * Permet de modifier la valeur d'une coordonnée
     * @param i la coordonnée
     * @return la valeur de la ieme coordonnée
     */
    float &operator[](int i);

    /**
     * Permet de consulter la valeur d'une coordonnée
     * @param i la coordonnée
     * @return la valeur de la ieme coordonnée
     */
    const float &operator[](int i) const;

private :
    // méthodes privées d'implémentation (si besoin)
};

/**
 * Fonction qui affiche le vecteur v dans le flux de sortie out.
 * @param v le veteur à afficher
 * @param out flux de sortie out
 */
void afficherVecteur(const Vecteur *v, std::ostream &out = std::cout);

/**
 * Fonction qui crée et initialise un vecteur dont les caractéristiques (nombres de dimensions et valeur de chaque coordonnée) sont fournies par l'utilisateur sur le flux d'entrée in.
 * @param in flux d'entrée in
 * @return le vecteur initialisé
 */
Vecteur *lireVecteur(std::istream &in = std::cin);

/**
 * Additionner deux vecteurs
 * @param v1 un vecteur
 * @param v2 un vecteur
 * @return un vecteur résultant de l'addition de v1 et v2
 */
Vecteur add(const Vecteur *v1, const Vecteur *v2);

/**
 * Produit scalaire
 * @param vecteur le vecteur à multiplier
 * @return le résultat du produit scalaire
 */
float &operator*(const Vecteur &vecteur1, const Vecteur &vecteur2);

/**
 * Affichage d'un vecteur
 * @param out flux de sortie
 * @param vecteur le vecteur à afficher
 * @return le flux de sortie
 */
std::ostream &operator<<(std::ostream &out, const Vecteur &vecteur);

/**
 * Lecture d'un vecteur
 * @param in flux d'entrée
 * @param vecteur le vecteur à lire
 * @return le flux d'entrée
 */
std::istream &operator>>(std::istream &in, Vecteur &vecteur);


#endif
