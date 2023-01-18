#ifndef IHM_H
#define IHM_H

#include "Carte.h"
#include <string>

#define TEMPS_DISTRIBUTION_CARTE 2

class MaitrePoulePoule;

class IHM
{
  private:
    MaitrePoulePoule* monMaitrePoulePoule;

  public:
    std::string  entreNomJoueur() const;
    unsigned int entreChoixJoueur() const;
    unsigned int entreReponseNbOeufs() const;

    void afficheMessageBienvenue() const;
    void afficheMenu(std::string nomJoueur) const;
    void afficheRegles() const;
    void afficheCarte(const Carte& carte) const;
    void afficheMessageDebutPartie() const;

    void filmFini();
    void partieGagnee(std::string nomJoueur);
    void partiePerdue(std::string nomJoueur, unsigned int compteurOeufs);

    void effaceEcran() const;
    void temporiseAffichageCourt() const;
    void temporiseAffichageMoyen() const;
    void temporiseCarte() const;
    void quitteJeu() const;
};

#endif // IHM_H