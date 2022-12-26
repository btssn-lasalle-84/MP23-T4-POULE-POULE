#ifndef CARTE_H
#define CARTE_H

#include <string>

#define NB_CARTES_OEUF 15
#define NB_CARTES_POULE 10
#define NB_CARTES_RENARD 10
#define NB_CARTES_COQ 1

class Carte
{
    private:
        std::string symbole;
        unsigned int valeurCarte;

    public:
        Carte();
        Carte(std::string symbole, unsigned int valeurCarte);
        ~Carte();
};

#endif