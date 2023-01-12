#ifndef MAITREPOULEPOULE_H
#define MAITREPOULEPOULE_H

#include <string>
#include <vector>
#include "Carte.h"

#define DEBUG_MAITREPOULEPOULE

class Carte;
class Joueur;
class IHM;

class MaitrePoulePoule
{
  private:
    Joueur*            monJoueur;
    IHM*               monIHM;
    std::vector<Carte> paquetCartes;
    unsigned int       nbPointJoueur;
    unsigned int       compteurOeuf;
    unsigned int       compteurOeufCouve;

  public:
    MaitrePoulePoule();
    ~MaitrePoulePoule();
    void               jouePartie();
    void               melangePaquet();
    void               distribueCartes();
    void               deroulePartie();
    void               compteNbOeuf(const Carte& carte);
    void               verifieReponseJoueur();
    std::vector<Carte> creeCartesOeuf();
    std::vector<Carte> creeCartesPoule();
    std::vector<Carte> creeCartesRenard();
    std::vector<Carte> creeCartesCOQ();
    void               creePaquetCartes();
};

#endif