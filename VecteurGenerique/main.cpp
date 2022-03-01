#include <iostream>
#include "vecteur.h"


void ask_and_add_two_vecteur() {
    // read a Vecteur
    std::cout << "Vecteur 1 : ";
    Vecteur<int> *vecteur1 = lireVecteur<int>(std::cin);
    // read second Vecteur
    std::cout << "Vecteur 2 : ";
    Vecteur<int> *vecteur2 = lireVecteur<int>(std::cin);

    // add two Vecteur
    Vecteur<int> vecteur3 = add(vecteur1, vecteur2);

    // print Vecteur
    afficherVecteur(&vecteur3, std::cout);

    //delete
    delete vecteur1;
    delete vecteur2;
}

void ask_and_add_two_vecteur_string() {
    // read a Vecteur
    std::cout << "Vecteur 1 : ";
    Vecteur<std::string> *vecteur1 = lireVecteur<std::string>(std::cin);
    // read second Vecteur
    std::cout << "Vecteur 2 : ";
    Vecteur<std::string> *vecteur2 = lireVecteur<std::string>(std::cin);

    // add two Vecteur
    Vecteur<std::string> vecteur3 = add(vecteur1, vecteur2);

    // print Vecteur
    afficherVecteur(&vecteur3, std::cout);

    //delete
    delete vecteur1;
    delete vecteur2;
}

void operator_read_std() {
    // read a vecteur using the >> operator
    std::cout << "Vecteur : ";
    Vecteur<int> vecteur1(2);
    std::cin >> vecteur1;
    std::cout << vecteur1;
}

void produit_scalaire_string() {
//    Vecteur<float> vecteur1(1, 3.0);
//    Vecteur<std::string> vecteur2(1, "a");
//    float result = vecteur1 * vecteur2;
//    std::cout << result;

}

void produit_scalaire_int_float() {
    Vecteur<float> vecteur1(1, 3.0);
    Vecteur<int> vecteur2(1, 3);
    float result = vecteur1 * vecteur2;
    std::cout << result;

}

void add_int_and_float() {
    Vecteur<int> vecteur1(1, 3.0);
    Vecteur<float> vecteur2(1, 3);
    Vecteur<int> result = vecteur1 + vecteur2;
    std::cout << result;
}

int main() {
    add_int_and_float();

    return 0;
}
