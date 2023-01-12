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
    unsigned int entreChoixJoueur() const;
    unsigned int entreReponseNbOeufs() const;

    void afficheMenu() const;
    void afficheRegles() const;
    void afficheCarte(const Carte& carte) const;

    void partieFinie();
    void partieGagnee();
    void partiePerdue();

    void effacerEcran() const;
    void temporiseAffichage() const;
    void temporiseCarte() const;
};

#endif // IHM_H