/*
 * main.cpp
 *
 *  Created on: 8 mars 2013
 *      Author: engel
 */

#include <iostream>
#include "constantes.h"
#include "enregistreur_fichier.h"
#include "enregistreur_fichier_texte.h"
//#include "harmonique.h"
#include "signal_constant.h"
#include "harmonique.h"
#include "filtre/multiplicateur.h"
#include "filtre/operation_binaire.h"
#include "filtre/volume.h"

void
q2_signal_constant() {
    signal_constant constant(0.5);
    enregistreur_fichier_texte enregistreur("../out/02_constant.txt", 1);
    enregistreur.connecterEntree(constant.getSortie(0), 0);
    // générer des valeurs
    for (unsigned int i = 0; i < 50; ++i) {
        constant.calculer();
        enregistreur.calculer();
    }
}

void
q4_harmonique() {
    harmonique la440(440, 0); // la 440Hz (voir fr.wikipedia.org/wiki/Note_de_musique)
    enregistreur_fichier enregistreur("../out/04_harmonique.raw", 1);    // fichier mono
    enregistreur.connecterEntree(la440.getSortie(0), 0);
    // produire 2 secondes de son
    for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
        la440.calculer();
        enregistreur.calculer();
    }
}

/**
 * Question 9 : Programmez la classe multiplicateur et testez-la en reprenant votre précédent programme de test et en multipliant un la 440Hz avec un la 880Hz.
 */
void q9_multiplicateur() {
    harmonique la440(440, 0);
    harmonique la880(880, 0);
    enregistreur_fichier enregistreur("../out/09_multiplicateur.raw", 1);
    multiplicateur multiplicateur_filtre;
    multiplicateur_filtre.connecterEntree(la440.getSortie(0), 0);
    multiplicateur_filtre.connecterEntree(la880.getSortie(0), 1);
    enregistreur.connecterEntree(multiplicateur_filtre.getSortie(0), 0);

    for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
        la440.calculer();
        la880.calculer();
        multiplicateur_filtre.calculer();
        enregistreur.calculer();
    }
}

/**
 * Question 11 : Testez votre classe en remplaçant, dans votre programme de test, le filtre multiplicateur par un filtre operation_binaire correctement paramétré et jouant le rôle d'un filtre multiplicateur. Vous devriez obtenir le même résultat qu'avec le multiplicateur programmé ci-dessus.
 */
void q11_operation_binaire() {
    harmonique la440(440, 0);
    harmonique la880(880, 0);
    enregistreur_fichier enregistreur("../out/11_operation_binaire.raw", 1);
    operation_binaire<std::multiplies<>> filtre;
    filtre.connecterEntree(la440.getSortie(0), 0);
    filtre.connecterEntree(la880.getSortie(0), 1);
    enregistreur.connecterEntree(filtre.getSortie(0), 0);

    for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
        la440.calculer();
        la880.calculer();
        filtre.calculer();
        enregistreur.calculer();
    }
}

void q12_volume() {
    harmonique la440(440, 0);
    enregistreur_fichier enregistreur("../out/12_volume.raw", 1);
    volume filtre(0.5);
    filtre.connecterEntree(la440.getSortie(0), 0);
    enregistreur.connecterEntree(filtre.getSortie(0), 0);

    for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
        la440.calculer();
        filtre.calculer();
        enregistreur.calculer();
    }
}

int
main() {
    q2_signal_constant();
    q4_harmonique();
    q9_multiplicateur();
    q11_operation_binaire();
    q12_volume();
    return 0;
}
