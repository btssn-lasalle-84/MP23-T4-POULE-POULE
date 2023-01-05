#ifndef IHM_H
#define IHM_H

#include <string>

#define TEMPS_DISTRIBUTION_CARTE 2

class IHM
{
  private:
    unsigned int choixJoueur;
    std::string  nomJoueur;
    unsigned int compteurOeuf;
    unsigned int compteurOeufCouve;
    unsigned int carteTiree;
    unsigned int reponseJoueur;

  public:
    void afficheMenu();
    void demarrePartie();
    void afficheRegles();
    void melange();
    void deroulementPartie();
};

#endif // IHM_H