#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

class MaitrePoulePoule;

class Joueur
{
  private:
    MaitrePoulePoule* monMaitrePoulePoule;
    std::string       nomJoueur;

  public:
    Joueur();
    Joueur(std::string nomJoueur);
    std::string getNomJoueur() const;
};

#endif // JOUEUR_H