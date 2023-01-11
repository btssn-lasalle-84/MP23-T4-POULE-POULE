#include "MaitrePoulePoule.h"
#include "Carte.h"
#include "IHM.h"
#include <string>
#include <vector>
#include <algorithm>

MaitrePoulePoule::MaitrePoulePoule() : nbPointJoueur(0)
{
    creePaquetCartes();
}

MaitrePoulePoule::MaitrePoulePoule(unsigned int nbPointJoueur) :
    nbPointJoueur(nbPointJoueur)
{
}

void MaitrePoulePoule::jouePartie()
{
    monIHM->afficheMenu();
}

void MaitrePoulePoule::creeCartesOeuf()
{
    for(int i = 0; i < NB_CARTES_OEUF; i++)
    {
        cartesOeuf.emplace_back(Carte::ValeurCarte::Oeuf);
    }
}

void MaitrePoulePoule::creeCartesPoule()
{
    for(int i = 0; i < NB_CARTES_POULE; i++)
    {
        cartesPoule.emplace_back(Carte::ValeurCarte::Poule);
    }
}

void MaitrePoulePoule::creeCartesRenard()
{
    for(int i = 0; i < NB_CARTES_RENARD; i++)
    {
        cartesRenard.emplace_back(Carte::ValeurCarte::Renard);
    }
}

void MaitrePoulePoule::creeCartesCOQ()
{
    for(int i = 0; i < NB_CARTES_COQ; i++)
    {
        cartesCoq.emplace_back(Carte::ValeurCarte::Coq);
    }
}

void MaitrePoulePoule::creePaquetCartes()
{
    creeCartesOeuf();
    creeCartesPoule();
    creeCartesRenard();
    creeCartesCOQ();

    paquetCartes.insert(paquetCartes.end(),
                        cartesOeuf.begin(),
                        cartesOeuf.end());
    paquetCartes.insert(paquetCartes.end(),
                        cartesPoule.begin(),
                        cartesPoule.end());
    paquetCartes.insert(paquetCartes.end(),
                        cartesRenard.begin(),
                        cartesRenard.end());
    paquetCartes.insert(paquetCartes.end(), cartesCoq.begin(), cartesCoq.end());
}

void MaitrePoulePoule::melangePaquet()
{
    std::random_shuffle(paquetCartes.begin(), paquetCartes.end());
}