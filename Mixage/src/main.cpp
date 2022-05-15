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
#include "filtre/mixeur.h"
#include "utils/lecteur_fichier.h"
#include "filtre/fade.h"
#include "filtre/fade_in.h"

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

void q15_compose() {
    {
        mixeur mixeur_filter({0.5, 1});
        harmonique la440(440, 0);
        harmonique la880(880, 0);
        mixeur_filter.connecterEntree(la440.getSortie(0), 0);
        mixeur_filter.connecterEntree(la880.getSortie(0), 1);
        enregistreur_fichier enregistreur("../out/q15_compose_1.raw", 1);
        enregistreur.connecterEntree(mixeur_filter.getSortie(0), 0);
        for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
            la440.calculer();
            la880.calculer();
            mixeur_filter.calculer();
            enregistreur.calculer();
        }
    }
    {
        mixeur mixeur_filter({1, 0.5});
        harmonique la440(440, 0);
        harmonique la880(880, 0);
        mixeur_filter.connecterEntree(la440.getSortie(0), 0);
        mixeur_filter.connecterEntree(la880.getSortie(0), 1);
        enregistreur_fichier enregistreur("../out/q15_compose_2.raw", 1);
        enregistreur.connecterEntree(mixeur_filter.getSortie(0), 0);
        for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
            la440.calculer();
            la880.calculer();
            mixeur_filter.calculer();
            enregistreur.calculer();
        }
    }
}

void q16_lecteur_fichier_mono() {
    lecteur_fichier lecteur("../raw/mono.raw", 1);
    enregistreur_fichier enregistreur("../out/q16_lecteur_fichier_mono.raw", 1);
    enregistreur.connecterEntree(lecteur.getSortie(0), 0);
    while (lecteur.can_read()) {
        lecteur.calculer();
        enregistreur.calculer();
    }
}

void q16_lecteur_fichier_stereo() {
    lecteur_fichier lecteur("../raw/stereo.raw", 2);
    enregistreur_fichier enregistreur("../out/q16_lecteur_fichier_stereo.raw", 2);
    enregistreur.connecterEntree(lecteur.getSortie(0), 0);
    enregistreur.connecterEntree(lecteur.getSortie(1), 1);
    while (lecteur.can_read()) {
        lecteur.calculer();
        enregistreur.calculer();
    }
}

void q17_mixage_piste_audio() {

}

void q181_fade_in() {
    lecteur_fichier lecteur("../raw/mono.raw", 1);
    enregistreur_fichier enregistreur("../out/q181_fade_in.raw", 1);

    fade_in fade_filter(2, 2);
    fade_filter.connecterEntree(lecteur.getSortie(0), 0);
    enregistreur.connecterEntree(fade_filter.getSortie(0), 0);
    while (lecteur.can_read()) {
        lecteur.calculer();
        fade_filter.calculer();
        enregistreur.calculer();
    }
}

int
main() {
//    q2_signal_constant();
//    q4_harmonique();
//    q9_multiplicateur();
//    q11_operation_binaire();
//    q12_volume();
//    q15_compose();
    q16_lecteur_fichier_mono();
    q16_lecteur_fichier_stereo();
    q181_fade_in();
    return 0;
}
