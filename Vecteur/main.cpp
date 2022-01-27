#include <iostream>
#include "vecteur.h"

using std::cout;

/**
 *  Ce programme devra demander à l'utilisateur de saisir un vecteur et ensuite l'afficher. Dans un second temps, ce programme devra demander à l'utilisateur de modifier l'une des coordonnées du vecteur.
 */
void simple_input() {
    cout << "Veuillez saisir un vecteur :" << std::endl;
    Vecteur *vecteur = lireVecteur(std::cin);
    cout << "Affichage du vecteur :" << std::endl;
    afficherVecteur(vecteur, cout);

//    Modification d'une coordonnée
    cout << std::endl << "Quelle coordonnée souhaitez-vous modifier ?" << std::endl;
    int coord_index;
    std::cin >> coord_index;
    while (coord_index < 0 || coord_index >= vecteur->dimensions()) {
        cout << "Veuillez saisir un nombre entre 0 et " << vecteur->dimensions() << " (non inclus)" << std::endl;
        std::cin >> coord_index;
    }
    cout << "Quelle valeur souhaitez vous mettre ?" << std::endl;
    float value;
    std::cin >> value;
    vecteur->set(coord_index, value);
    cout << "Affichage du vecteur :" << std::endl;
    afficherVecteur(vecteur, cout);

    delete vecteur;
}

/**
 * Une fois cette fonction réalisée, modifiez votre programme principal afin d'afficher la valeur de la somme de deux vecteurs saisis par l'utilisateur.
 */
void add_two_vectors() {
    cout << "Veuillez saisir un premier vecteur :" << std::endl;
    Vecteur *vecteur1 = lireVecteur(std::cin);

    cout << "Veuillez saisir un second vecteur :" << std::endl;
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
    Vecteur vecteur1(1);

    vecteur1 = Vecteur(2);

    afficherVecteur(&vecteur1, cout);

}

void addition() {
    Vecteur vecteur1 (3);
    Vecteur vecteur2 (3);
    vecteur1.set(0, 1);
    vecteur2.set(0, 1);

    Vecteur vecteur3 = vecteur1 + vecteur2;

    afficherVecteur(&vecteur3, cout);

}

void get() {
    Vecteur vecteur1(1);
    vecteur1.set(0, 1);
    cout << vecteur1[0];
}

void set() {
    Vecteur vecteur1(1);
    vecteur1[0] = 5;
    cout << vecteur1[0];
}

void enter_and_display() {
    Vecteur vecteur1(3);
    std::cin >> vecteur1;

    cout << vecteur1;
}


/** \brief Programme principal */
int main() {

    Vecteur * vecteur = new Vecteur(3);
    vecteur->set(0, 1);

    Vecteur * vecteur2 = new Vecteur(3);
    vecteur2->set(0, 1);
    delete vecteur;
    delete vecteur2;

    return 0;
}


