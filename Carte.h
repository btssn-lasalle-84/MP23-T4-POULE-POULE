#ifndef CARTE_H
#define CARTE_H

#include <string>

#define NB_CARTES_OEUF   15
#define NB_CARTES_POULE  10
#define NB_CARTES_RENARD 10
#define NB_CARTES_COQ    1
#define NB_CARTES_CANARD 2

class Carte
{
  public:
    enum ValeurCarte
    {
        Oeuf,
        Poule,
        Renard,
        Coq,
        Canard,
    };
    Carte();
    Carte(ValeurCarte valeurCarte);
    ~Carte();
    unsigned int getValeurCarte() const;

  private:
    ValeurCarte valeurCarte;
};

#endif