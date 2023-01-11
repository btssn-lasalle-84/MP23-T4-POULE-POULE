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
    void        setNomJoueur(std::string nomJoueur);
};

#endif // JOUEUR_H