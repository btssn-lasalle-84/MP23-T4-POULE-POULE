#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <string>

#define NB_CARTES 36
class MaitrePoulePoule;

class Carte
{
    private:
        MaitrePoulePoule *maPoule;
        std::string symbole;
        unsigned int valeurCarte;

    public:
        Carte();
        Carte(std::string symbole, unsigned int valeurCarte);
        ~Carte();
};

#endif