#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

class Joueur
{
  private:
    std::string  nomJoueur;
    unsigned int choixJoueur;

  public:
    Joueur();
    Joueur(std::string nomJoueur, unsigned int choixJoueur);
    std::string  getNomJoueur() const;
    void         setNomJoueur(std::string nomJoueur);
    unsigned int getChoixJoueur() const;
    void         setChoixJoueur(unsigned int choixJoueur);
};
#endif // JOUEUR_H