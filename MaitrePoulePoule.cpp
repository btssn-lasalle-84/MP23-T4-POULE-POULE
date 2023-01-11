#include "MaitrePoulePoule.h"
#include "Joueur.h"
#include "IHM.h"
#include "Carte.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <ctime>

#ifdef DEBUG_MAITREPOULEPOULE
#include <iostream>
#endif

MaitrePoulePoule::MaitrePoulePoule() :
    monJoueur(new Joueur), monIHM(new IHM), nbPointJoueur(0)
{
#ifdef DEBUG_MAITREPOULEPOULE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] " << this
              << std::endl;
#endif
    creePaquetCartes();
    melangePaquet();
}

MaitrePoulePoule::~MaitrePoulePoule()
{
    delete monIHM;
    delete monJoueur;
#ifdef DEBUG_MAITREPOULEPOULE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] " << this
              << std::endl;
#endif
}

void MaitrePoulePoule::jouePartie()
{
    std::string nomJoueur = monIHM->entreNomJoueur();
    monJoueur->setNomJoueur(nomJoueur);

#ifdef DEBUG_MAITREPOULEPOULE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
              << "nomJoueur = " << monJoueur->getNomJoueur() << std::endl;
#endif

    monIHM->afficheMenu();
    deroulePartie();
}

void MaitrePoulePoule::melangePaquet()
{
    std::srand(unsigned(std::time(0)));
    std::random_shuffle(paquetCartes.begin(), paquetCartes.end());
}

void MaitrePoulePoule::distribueCartes()
{
    for(unsigned int i = 0; i < paquetCartes.size(); i++)
    {
        monIHM->afficheCarte(paquetCartes[i]);
    }
}

void MaitrePoulePoule::deroulePartie()
{
    unsigned int choixJoueur = monIHM->entreChoixJoueur();
    monJoueur->setChoixJoueur(choixJoueur);

    if(monJoueur->getChoixJoueur() == 1)
    {
        system("clear");
        distribueCartes();
    }
    else if(monJoueur->getChoixJoueur() == 2)
    {
        system("clear");
        monIHM->afficheRegles();
    }
    else
    {
#ifdef DEBUG_MAITREPOULEPOULE
        std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                  << "choixJoueur = " << monJoueur->getChoixJoueur()
                  << std::endl;
#endif
        sleep(2);
        system("clear");
        jouePartie();
    }
}

std::vector<Carte> MaitrePoulePoule::creeCartesOeuf()
{
    std::vector<Carte> cartes;
    for(int i = 0; i < NB_CARTES_OEUF; i++)
    {
        cartes.emplace_back(Carte::ValeurCarte::Oeuf);
    }
    return cartes;
}

std::vector<Carte> MaitrePoulePoule::creeCartesPoule()
{
    std::vector<Carte> cartes;
    for(int i = 0; i < NB_CARTES_POULE; i++)
    {
        cartes.emplace_back(Carte::ValeurCarte::Poule);
    }
    return cartes;
}

std::vector<Carte> MaitrePoulePoule::creeCartesRenard()
{
    std::vector<Carte> cartes;
    for(int i = 0; i < NB_CARTES_RENARD; i++)
    {
        cartes.emplace_back(Carte::ValeurCarte::Renard);
    }
    return cartes;
}

std::vector<Carte> MaitrePoulePoule::creeCartesCOQ()
{
    std::vector<Carte> cartes;
    for(int i = 0; i < NB_CARTES_COQ; i++)
    {
        cartes.emplace_back(Carte::ValeurCarte::Coq);
    }
    return cartes;
}

void MaitrePoulePoule::creePaquetCartes()
{
    std::vector<Carte> cartesOeuf;
    std::vector<Carte> cartesPoule;
    std::vector<Carte> cartesRenard;
    std::vector<Carte> cartesCoq;

    cartesOeuf   = creeCartesOeuf();
    cartesPoule  = creeCartesPoule();
    cartesRenard = creeCartesRenard();
    cartesCoq    = creeCartesCOQ();

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