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
    compteurOeufsCouves(0), compteurVersDeTerre(0), compteurOeufsAutruche(0)
{
    creePaquetCartes();
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
    monIHM->effaceEcran();
    monIHM->afficheMessageBienvenue();

    std::string nomJoueur = monIHM->entreNomJoueur();
    monJoueur->setNomJoueur(nomJoueur);

#ifdef DEBUG_MAITREPOULEPOULE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
              << "nomJoueur = " << monJoueur->getNomJoueur() << std::endl;
#endif

    bool sortie = false;
    do
    {
        reinitialiseNbPointsJoueur();
        monIHM->afficheMenu(monJoueur->getNomJoueur());

        unsigned int choixJoueur = monIHM->entreChoixJoueur();
        monJoueur->setChoixJoueur(choixJoueur);

#ifdef DEBUG_MAITREPOULEPOULE
        std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                  << "choixJoueur = " << monJoueur->getChoixJoueur()
                  << std::endl;
#endif

        monIHM->effaceEcran();
        unsigned int choix = monJoueur->getChoixJoueur();
        sortie             = gereChoix(choix);
    } while(!sortie);
}

unsigned int MaitrePoulePoule::getCompteurOeufs() const
{
    return compteurOeufs;
}

void MaitrePoulePoule::setCompteurOeufs(unsigned int compteurOeufs)
{
    this->compteurOeufs = compteurOeufs;
}

unsigned int MaitrePoulePoule::getNbPointsJoueur() const
{
    return nbPointsJoueur;
}

void MaitrePoulePoule::reinitialiseCompteurs()
{
    compteurOeufs         = 0;
    compteurOeufsCouves   = 0;
    compteurVersDeTerre   = 0;
    compteurOeufsAutruche = 0;
}

void MaitrePoulePoule::reinitialiseNbPointsJoueur()
{
    nbPointsJoueur = 0;
}

void MaitrePoulePoule::derouleFilm()
{
    reinitialiseCompteurs();
    distribueCartes(monJoueur->getChoixDifficulte());

    monIHM->finitFilm();
    convertitOeufAutrucheEnOeuf();
    unsigned int reponseNbOeuf = monIHM->entreReponseNbOeufs();
    monJoueur->setReponseNbOeuf(reponseNbOeuf);
    if(verifieReponseJoueur())
    {
        monIHM->gagnePartie(monJoueur->getNomJoueur());
        nbPointsJoueur = nbPointsJoueur + 1;
    }
    else
    {
        monIHM->perdPartie(monJoueur->getNomJoueur(), getCompteurOeufs());
    }
    monIHM->temporiseAffichageLong();
}

void MaitrePoulePoule::distribueCartes(unsigned int choixDifficulte)
{
    for(unsigned int numeroCarte = 0;
        numeroCarte < paquetCartes.size() &&
        !estPartieFinie(paquetCartes[numeroCarte]);
        numeroCarte++)
    {
        monIHM->afficheCarte(paquetCartes[numeroCarte + 1],
                             numeroCarte,
                             choixDifficulte);
        compteNbOeufs(paquetCartes[numeroCarte + 1]);
#ifdef DEBUG_MAITREPOULEPOULE
        std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
                  << "numeroCarte = " << numeroCarte + 1 << std::endl;
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

std::vector<Carte> MaitrePoulePoule::creeCartesCoq()
{
    std::vector<Carte> cartes;
    for(int i = 0; i < NB_CARTES_COQ; i++)
    {
        cartes.emplace_back(Carte::ValeurCarte::Coq);
    }
    return cartes;
}

std::vector<Carte> MaitrePoulePoule::creeCartesCanard()
{
    std::vector<Carte> cartes;
    for(int i = 0; i < NB_CARTES_CANARD; i++)
    {
        cartes.emplace_back(Carte::ValeurCarte::Canard);
    }
    return cartes;
}

std::vector<Carte> MaitrePoulePoule::creeCartesVerDeTerre()
{
    std::vector<Carte> cartes;
    for(int i = 0; i < NB_CARTES_VER_DE_TERRE; i++)
    {
        cartes.emplace_back(Carte::ValeurCarte::VerDeTerre);
    }
    return cartes;
}

std::vector<Carte> MaitrePoulePoule::creeCartesOeufAutruche()
{
    std::vector<Carte> cartes;
    for(int i = 0; i < NB_CARTES_OEUF_AUTRUCHE; i++)
    {
        cartes.emplace_back(Carte::ValeurCarte::OeufAutruche);
    }
    return cartes;
}

std::vector<Carte> MaitrePoulePoule::creeCartesFermier()
{
    std::vector<Carte> cartes;
    for(int i = 0; i < NB_CARTES_FERMIER; i++)
    {
        cartes.emplace_back(Carte::ValeurCarte::Fermier);
    }
    return cartes;
}

void MaitrePoulePoule::creePaquetCartes()
{
    std::vector<Carte> cartesOeuf;
    std::vector<Carte> cartesPoule;
    std::vector<Carte> cartesRenard;
    std::vector<Carte> cartesCoq;
    std::vector<Carte> cartesCanard;
    std::vector<Carte> cartesVerDeTerre;
    std::vector<Carte> cartesOeufAutruche;
    std::vector<Carte> cartesFermier;

    cartesOeuf         = creeCartesOeuf();
    cartesPoule        = creeCartesPoule();
    cartesRenard       = creeCartesRenard();
    cartesCoq          = creeCartesCoq();
    cartesCanard       = creeCartesCanard();
    cartesVerDeTerre   = creeCartesVerDeTerre();
    cartesOeufAutruche = creeCartesOeufAutruche();
    cartesFermier      = creeCartesFermier();

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
    paquetCartes.insert(paquetCartes.end(),
                        cartesCanard.begin(),
                        cartesCanard.end());
    paquetCartes.insert(paquetCartes.end(),
                        cartesVerDeTerre.begin(),
                        cartesVerDeTerre.end());
    paquetCartes.insert(paquetCartes.end(),
                        cartesOeufAutruche.begin(),
                        cartesOeufAutruche.end());
    paquetCartes.insert(paquetCartes.end(),
                        cartesFermier.begin(),
                        cartesFermier.end());
}

void MaitrePoulePoule::melangePaquet()
{
    std::srand(unsigned(std::time(0)));
    std::random_shuffle(paquetCartes.begin(), paquetCartes.end());
}

void MaitrePoulePoule::compteNbOeufs(const Carte& carte)
{
    switch(carte.getValeurCarte())
    {
        case Carte::ValeurCarte::Oeuf:
            compteurOeufs = compteurOeufs + 1;
            break;
        case Carte::ValeurCarte::Poule:
            if(compteurVersDeTerre == 0 && compteurOeufs >= 1)
            {
                compteurOeufs       = compteurOeufs - 1;
                compteurOeufsCouves = compteurOeufsCouves + 1;
            }
            else
            {
                compteurVersDeTerre = compteurVersDeTerre - 1;
            }
            break;
        case Carte::ValeurCarte::Renard:
            if(compteurOeufsCouves >= 1)
            {
                compteurOeufsCouves = compteurOeufsCouves - 1;
                compteurOeufs       = compteurOeufs + 1;
            }
            break;
        case Carte::ValeurCarte::Coq:
            break;
        case Carte::ValeurCarte::Canard:
            break;
        case Carte::ValeurCarte::VerDeTerre:
            compteurVersDeTerre = compteurVersDeTerre + 1;
            break;
        case Carte::ValeurCarte::OeufAutruche:
            compteurOeufsAutruche = compteurOeufsAutruche + 1;
            break;
        case Carte::ValeurCarte::Fermier:
            compteurOeufs         = 0;
            compteurOeufsAutruche = 0;
            break;
        default:
            break;
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
              << "compteurOeufs = " << compteurOeufs << std::endl;
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
              << "compteurOeufsAutruche = " << compteurOeufsAutruche
              << std::endl;
#endif
}

void MaitrePoulePoule::convertitOeufAutrucheEnOeuf()
{
    compteurOeufs = compteurOeufs + (compteurOeufsAutruche * 2);
}

bool MaitrePoulePoule::verifieReponseJoueur() const
{
    return (monJoueur->getReponseNbOeuf() == compteurOeufs);
}

bool MaitrePoulePoule::gereChoix(unsigned int choix)
{
    unsigned int numeroManche = 0;
    switch(choix)
    {
        case ChoixMenu::JouePartie:
            monIHM->afficheMenuNiveauxDifficultes(monJoueur->getNomJoueur());
            recupereChoixDifficulte();
            do
            {
                melangePaquet();
                monIHM->effaceEcran();
                monIHM->afficheMessageDebutManche(numeroManche);
                derouleFilm();
                numeroManche = numeroManche + 1;
            } while(numeroManche != NOMBRE_MANCHES);
            monIHM->afficheMessageFinPartie(getNbPointsJoueur());
            break;
        case ChoixMenu::Regles:
            monIHM->afficheRegles();
            break;
        case ChoixMenu::QuitteJeu:
            monIHM->quitteJeu();
            return true;
        default:
            break;
    }
    return false;
}

void MaitrePoulePoule::recupereChoixDifficulte() const
{
    unsigned int choixDifficulte = monIHM->entreChoixDifficulte();
    monJoueur->setChoixDifficulte(choixDifficulte);
}