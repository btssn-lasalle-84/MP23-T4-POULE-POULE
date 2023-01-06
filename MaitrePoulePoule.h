#ifndef MAITREPOULEPOULE_H
#define MAITREPOULEPOULE_H

#include "Carte.h"
#include <string>
#include <vector>

class Carte;

class MaitrePoulePoule
{
  private:
    Carte              cartes;
    unsigned int       nbPointJoueur;
    std::vector<Carte> cartesOeuf;
    std::vector<Carte> cartesPoule;
    std::vector<Carte> cartesRenard;
    std::vector<Carte> cartesCoq;
    std::vector<Carte> paquetCartes;

  public:
    MaitrePoulePoule();
    MaitrePoulePoule(unsigned int nbPointJoueur);
    void creeCartesOeuf();
    void creeCartesPoule();
    void creeCartesRenard();
    void creeCartesCOQ();
    void creePaquetCartes();
    void melangePaquet();
};

#endif