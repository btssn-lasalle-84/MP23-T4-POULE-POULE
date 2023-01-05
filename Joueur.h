#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

class Joueur
{
  private:
    std::string nomJoueur;

  public:
    Joueur();
    Joueur(std::string nomJoueur);
    std::string getNomJoueur() const;
};

#endif // JOUEUR_H