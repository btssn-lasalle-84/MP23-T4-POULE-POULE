#ifndef MAITREPOULEPOULE_H
#define MAITREPOULEPOULE_H

#include <string>
#include <vector>
#include "Carte.h"

#define DEBUG_MAITREPOULEPOULE

// Choix de menu
#define JOUE_PARTIE 1
#define REGLES      2

class Carte;
class Joueur;
class IHM;

class MaitrePoulePoule
{
  private:
    Joueur*            monJoueur;
    IHM*               monIHM;
    std::vector<Carte> paquetCartes;
    unsigned int       nbPointsJoueur;
    unsigned int       compteurOeufs;
    unsigned int       compteurOeufsCouves;
    unsigned int       compteurVersDeTerre;

    void               derouleFilm();
    void               reinitialiseCompteurs();
    void               distribueCartes();
    bool               estPartieFinie(const Carte& carte) const;
    std::vector<Carte> creeCartesOeuf();
    std::vector<Carte> creeCartesPoule();
    std::vector<Carte> creeCartesRenard();
    std::vector<Carte> creeCartesCoq();
    std::vector<Carte> creeCartesCanard();
    std::vector<Carte> creeCartesVerDeTerre();
    void               creePaquetCartes();
    void               melangePaquet();
    void               compteNbOeufs(const Carte& carte);
    bool               verifieReponseJoueur() const;

  public:
    MaitrePoulePoule();
    ~MaitrePoulePoule();
    void         jouePartie();
    unsigned int getCompteurOeufs() const;
    void         setCompteurOeufs(unsigned int compteurOeufs);
};

#endif