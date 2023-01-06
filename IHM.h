#ifndef IHM_H
#define IHM_H

#include "Carte.h"
#include <string>

#define TEMPS_DISTRIBUTION_CARTE 2

class IHM
{
  private:
  public:
    void afficheMenu();
    void saisieNomJoueur();
    void afficheRegles();
    void afficheCarte(Carte carte);
};

#endif // IHM_H