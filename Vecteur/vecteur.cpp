/** \brief Ce fichier doit contenir l'ensemble des implémentations
relatives à la classe vecteur et aux fonctionnalités la concernant */

#include <cassert>
#include <iostream>
#include "vecteur.h"

Vecteur::Vecteur(int size, float default_value) : tab(new float[size]), size(size) {
    assert(size > 0);
    std::cout << "🐣 Construction d'un vecteur de taille " << size << "\n";
    for (int i = 0; i < size; ++i) {
        tab[i] = default_value;
    }
}

int Vecteur::dimensions() const {
    return size;
}

float Vecteur::get(int i) const {
    assert(i < size);
    return tab[i];
}

void Vecteur::set(int i, float value) {
    assert(i < size);
    tab[i] = value;
}

Vecteur::~Vecteur() {
    std::cout << "🗑 Destruction du vecteur ";
    afficherVecteur(this, std::cout);
    std::cout << "\n";
    delete[] tab;
}

Vecteur::Vecteur(const Vecteur &vecteur) {
    copy(vecteur);
}

Vecteur &Vecteur::operator=(const Vecteur &vecteur) {
    if (this != &vecteur) {
        delete[] tab;
        copy(vecteur);
    }
    return *this;
}

void Vecteur::copy(const Vecteur &vecteur) {
    size = vecteur.size;
    tab = new float[size];
    for (int i = 0; i < size; ++i) {
        tab[i] = vecteur.tab[i];
    }
}

Vecteur &Vecteur::operator+(const Vecteur &vecteur) {
    assert(size == vecteur.size);
    auto *result = new Vecteur(size);
    for (int i = 0; i < size; ++i) {
        result->tab[i] = tab[i] + vecteur.tab[i];
    }
    return *result;
}

float &Vecteur::operator[](int i) {
    assert(i < size);
    return tab[i];
}

float &Vecteur::operator[](int i) const {
    assert(i < size);
    return tab[i];
}


void afficherVecteur(const Vecteur *v, std::ostream &out) {
    out << "[";
    for (int i = 0; i < v->dimensions(); ++i) {
        out << v->get(i);
        if (i < v->dimensions() - 1) {
            out << ", ";
        }
    }
    out << "]";
}

Vecteur *lireVecteur(std::istream &in) {
    int size;
    in >> size;
    auto *vecteur = new Vecteur(size);
    for (int i = 0; i < size; ++i) {
        float value;
        in >> value;
        vecteur->set(i, value);
    }
    return vecteur;
}

Vecteur add(const Vecteur *v1, const Vecteur *v2) {
    assert(v1->dimensions() == v2->dimensions());
    Vecteur vecteur(v1->dimensions());
    for (int i = 0; i < v1->dimensions(); ++i) {
        vecteur.set(i, v1->get(i) + v2->get(i));
    }
    return vecteur;
}

float &operator*(const Vecteur &vecteur1, const Vecteur &vecteur2) {
    assert(vecteur1.dimensions() == vecteur2.dimensions());
    float result = 0;
    for (int i = 0; i < vecteur1.dimensions(); ++i) {
        result += vecteur1.get(i) * vecteur2.get(i);
    }
    return result;
}

std::ostream &operator<<(std::ostream &out, const Vecteur &vecteur) {
    afficherVecteur(&vecteur, out);
    return out;
}

std::istream &operator>>(std::istream &in, Vecteur &vecteur) {
    for (int i = 0; i < vecteur.dimensions(); ++i) {
        float value;
        in>>value;
        vecteur.set(i, value);
    }

    return in;
}

