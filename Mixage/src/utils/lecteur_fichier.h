//
// Created by Mael Kerichard on 12/05/2022.
//

#ifndef MIXAGE_LECTEUR_FICHIER_H
#define MIXAGE_LECTEUR_FICHIER_H


#include <fstream>
#include <iostream>
#include "../producteur_base.h"
#include "composant_exception.h"

class lecteur_fichier : public producteur_base {
private:
    std::ifstream fichier;
    const unsigned int _channelCount;
public:
    lecteur_fichier(const std::string &filePath, const unsigned int channelCount) : producteur_base(channelCount),
                                                                                    fichier(filePath, std::ios::binary),
                                                                                    _channelCount(channelCount) {
//        assert(channelCount >= 1 && channelCount <= 2); // Il peut y avoir des fichiers audios avec 5 ou 7 canaux ?
    }

    ~lecteur_fichier() override {
        fichier.close();
    }

    bool can_read() {
        return fichier.peek() != EOF;
    }

    void calculer() override {
        if (!fichier.is_open()) {
            throw composant_exception("Fin du fichier atteinte ou fichier inexistant");
        }
        for (int i = 0; i < _channelCount; ++i) {
            short int data;
            fichier.read((char *) &data, 2);
//            on normalise le résultat [−32768; 32767] -> [-1; 1]
            double result = data / 32768.0;
            producteur_base::getSortie(i)->inserer(result);
            if (!fichier.good()) {
                throw composant_exception("Le lecteur n'a pas pu lire le fichier");
            }
            if (fichier.eof()) {
                fichier.close();
            }
        }
    }
};


#endif //MIXAGE_LECTEUR_FICHIER_H
