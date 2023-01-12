#ifndef IHM_H
#define IHM_H

#include "Carte.h"
#include <string>

#define TEMPS_DISTRIBUTION_CARTE 2

class IHM
{
  private:
  public:
    std::string  entreNomJoueur() const;
    unsigned int entreChoixJoueur() const;
    unsigned int entreReponseNbOeufs() const;

    void afficheMenu(std::string nomJoueur) const;
    void afficheRegles() const;
    void afficheCarte(const Carte& carte) const;

    void filmFini();
    void partieGagnee(std::string nomJoueur);
    void partiePerdue(std::string nomJoueur);

    void effaceEcran() const;
    void temporiseAffichage() const;
    void temporiseCarte() const;
};

#endif // IHM_H