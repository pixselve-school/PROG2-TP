#include <iostream>
#include "vecteur.h"

using std::cout;

/**
 *  Ce programme devra demander à l'utilisateur de saisir un vecteur et ensuite l'afficher. Dans un second temps, ce programme devra demander à l'utilisateur de modifier l'une des coordonnées du vecteur.
 */
void simple_input() {
    cout << "Veuillez saisir un vecteur :\n";
    Vecteur *vecteur = lireVecteur(std::cin);
    cout << "Affichage du vecteur :\n";
    afficherVecteur(vecteur, cout);

//    Modification d'une coordonnée
    cout << "\nQuelle coordonnée souhaitez-vous modifier ?\n";
    int coord_index;
    std::cin >> coord_index;
    cout << "Quelle valeur souhaitez vous mettre ?\n";
    float value;
    std::cin >> value;
    vecteur->set(coord_index, value);
    cout << "Affichage du vecteur :\n";
    afficherVecteur(vecteur, cout);

    delete vecteur;
}

/**
 * Une fois cette fonction réalisée, modifiez votre programme principal afin d'afficher la valeur de la somme de deux vecteurs saisis par l'utilisateur.
 */
void add_two_vectors() {
    cout << "Veuillez saisir un premier vecteur :\n";
    Vecteur *vecteur1 = lireVecteur(std::cin);

    cout << "Veuillez saisir un second vecteur :\n";
    Vecteur *vecteur2 = lireVecteur(std::cin);
    Vecteur result = add(vecteur1, vecteur2);

    afficherVecteur(vecteur1, cout);
    cout << " + ";
    afficherVecteur(vecteur2, cout);
    cout << " = ";

    afficherVecteur(&result, cout);

    delete vecteur1;
    delete vecteur2;
}

void affectation() {
    auto *vecteur1 = new Vecteur(1);

    vecteur1 = new Vecteur(2);

    afficherVecteur(vecteur1, cout);

    delete vecteur1;
}

void addition() {
    auto *vecteur1 = new Vecteur(1);
    auto *vecteur2 = new Vecteur(1);
    vecteur1->set(0, 1);
    vecteur2->set(0, 1);

    Vecteur vecteur3 = *vecteur1 + *vecteur2;

    afficherVecteur(&vecteur3, cout);

    delete vecteur1;
    delete vecteur2;
}

void get() {
    auto *vecteur1 = new Vecteur(1);
    vecteur1->set(0, 1);
    cout<<vecteur1[0];

    delete vecteur1;
}

void set() {
    auto *vecteur1 = new Vecteur(1);
    (*vecteur1)[0] = 5;
    cout<<vecteur1[0];

    delete vecteur1;
}

void enter_and_display() {
    Vecteur vecteur1(3);
    std::cin>>vecteur1;

    cout<<vecteur1;
}


/** \brief Programme principal */
int main() {

    enter_and_display();

    return 0;
}


