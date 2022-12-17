#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <string>

class MaitrePoulePoule;
class Joueur
{
    private:
        MaitrePoulePoule* leMaitrePoulePoule;
        std::string nomJoueur;

    public:
        Joueur();
        Joueur(std::string nomJoueur);
        std::string getNomJoueur() const;
        MaitrePoulePoule* getMaitrePoulePoule();
        void setMaitrePoulePoule(MaitrePoulePoule* maitrePoulePoule);
};

#endif // JOUEUR_H