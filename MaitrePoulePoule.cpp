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
    monJoueur(new Joueur), monIHM(new IHM), nbPointsJoueur(0), compteurOeufs(0),
    compteurOeufsCouves(0)
{
#ifdef DEBUG_MAITREPOULEPOULE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] " << this
              << std::endl;
#endif
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

    //@TODO boucle

    monIHM->afficheMenu();

    unsigned int choixJoueur = monIHM->entreChoixJoueur();
    monJoueur->setChoixJoueur(choixJoueur);

#ifdef DEBUG_MAITREPOULEPOULE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
              << "choixJoueur = " << monJoueur->getChoixJoueur() << std::endl;
#endif

    monIHM->effacerEcran();
    switch(monJoueur->getChoixJoueur())
    {
        case JOUE_PARTIE:
            deroulePartie();
            break;
        case REGLES:
            monIHM->afficheRegles();
            break;
        default:
            break;
    }
}

void MaitrePoulePoule::reinitialiseCompteurs()
{
    nbPointsJoueur      = 0;
    compteurOeufs       = 0;
    compteurOeufsCouves = 0;
}

void MaitrePoulePoule::deroulePartie()
{
    creePaquetCartes();
    melangePaquet();
    reinitialiseCompteurs();
    distribueCartes();

    monIHM->partieFinie();
    unsigned int reponseNbOeuf = monIHM->entreReponseNbOeufs();
    monJoueur->setReponseNbOeuf(reponseNbOeuf);
    if(verifieReponseJoueur())
    {
        monIHM->partieGagnee();
    }
    else
    {
        monIHM->partiePerdue();
    }
}

void MaitrePoulePoule::distribueCartes()
{
    for(unsigned int numeroCarte = 0;
        numeroCarte < paquetCartes.size() &&
        !estPartieFinie(paquetCartes[numeroCarte]);
        numeroCarte++)
    {
        monIHM->afficheCarte(paquetCartes[numeroCarte]);
        compteNbOeuf(paquetCartes[numeroCarte]);
#ifdef DEBUG_MAITREPOULEPOULE
        std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                  << "numeroCarte = " << numeroCarte << std::endl;
#endif
    }
}

bool MaitrePoulePoule::estPartieFinie(const Carte& carte) const
{
    return (carte.getValeurCarte() == Carte::ValeurCarte::Coq);
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

void MaitrePoulePoule::melangePaquet()
{
    std::srand(unsigned(std::time(0)));
    std::random_shuffle(paquetCartes.begin(), paquetCartes.end());
}

void MaitrePoulePoule::compteNbOeuf(const Carte& carte)
{
    switch(carte.getValeurCarte())
    {
        case Carte::ValeurCarte::Oeuf:
            compteurOeufs = compteurOeufs + 1;
            break;
        case Carte::ValeurCarte::Poule:
            // si il y a un oeuf
            compteurOeufs       = compteurOeufs - 1;
            compteurOeufsCouves = compteurOeufsCouves + 1;
            // finsi
            break;
        case Carte::ValeurCarte::Renard:
            // si ...
            compteurOeufsCouves = compteurOeufsCouves - 1;
            compteurOeufs       = compteurOeufs + 1;
            // fin si
            break;
        case Carte::ValeurCarte::Coq:
            break;
        default:
#ifdef DEBUG_MAITREPOULEPOULE
            std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                      << "carte inconnue !!!" << std::endl;
#endif
    }
#ifdef DEBUG_MAITREPOULEPOULE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
              << "carte.getValeurCarte() = " << carte.getValeurCarte()
              << std::endl;
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
              << "compteurOeuf = " << compteurOeufs << std::endl;
#endif
}

bool MaitrePoulePoule::verifieReponseJoueur() const
{
    if(monJoueur->getReponseNbOeuf() == compteurOeufs)
    {
        return true;
    }
    else
    {
        return false;
    }
}
