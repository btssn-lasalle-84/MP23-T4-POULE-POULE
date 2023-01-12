#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

class Joueur
{
  private:
    std::string  nomJoueur;
    unsigned int choixJoueur;
    unsigned int reponseNbOeuf;

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
};

#endif // JOUEUR_H