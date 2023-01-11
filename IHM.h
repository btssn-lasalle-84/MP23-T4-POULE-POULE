#ifndef IHM_H
#define IHM_H

#include "Carte.h"
#include <string>

#define TEMPS_DISTRIBUTION_CARTE 2

class IHM
{
  private:
  public:
    std::string  entreNomJoueur();
    void         afficheMenu();
    unsigned int entreChoixJoueur();
    void         afficheRegles();
    void         afficheCarte();
};

#endif // IHM_H