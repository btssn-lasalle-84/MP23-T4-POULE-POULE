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

  public:
    MaitrePoulePoule();
    ~MaitrePoulePoule();
    void               jouePartie();
    std::vector<Carte> creeCartesOeuf();
    std::vector<Carte> creeCartesPoule();
    std::vector<Carte> creeCartesRenard();
    std::vector<Carte> creeCartesCOQ();
    void               creePaquetCartes();
    void               melangePaquet();
};

#endif