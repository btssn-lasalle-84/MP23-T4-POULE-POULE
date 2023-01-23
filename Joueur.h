#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

class Joueur
{
  private:
    std::string  nomJoueur;
    unsigned int choixJoueur;
    unsigned int reponseNbOeuf;
    unsigned int choixDifficulte;

  public:
    Joueur();
    Joueur(std::string  nomJoueur,
           unsigned int choixJoueur,
           unsigned int reponseNbOeuf);
    std::string  getNomJoueur() const;
    void         setNomJoueur(std::string nomJoueur);
    unsigned int getChoixJoueur() const;
    void         setChoixJoueur(unsigned int choixJoueur);
    unsigned int getReponseNbOeuf() const;
    void         setReponseNbOeuf(unsigned int reponseNbOeuf);
    unsigned int getChoixDifficulte() const;
    void         setChoixDifficulte(unsigned int choixDifficulte);
};

#endif // JOUEUR_H