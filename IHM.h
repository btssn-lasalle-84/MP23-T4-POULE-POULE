#ifndef IHM_H
#define IHM_H

#include "Carte.h"
#include <string>

#define TEMPS_DISTRIBUTION_CARTE 2

class Joueur;

class IHM
{
  private:
    Joueur* monJoueur;

  public:
    std::string  entreNomJoueur() const;
    void         afficheMenu() const;
    unsigned int entreChoixJoueur() const;
    void         afficheRegles() const;
    void         afficheCarte(const Carte& carte) const;
    void         finManche();
    unsigned int entreReponseNbOeufs() const;
    void         gagnePartie();
    void         perduPartie();
};

#endif // IHM_H