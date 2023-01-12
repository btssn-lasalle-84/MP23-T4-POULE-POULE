#ifndef CARTE_H
#define CARTE_H

#include <string>

#define NB_CARTES_OEUF   15
#define NB_CARTES_POULE  10
#define NB_CARTES_RENARD 10
#define NB_CARTES_COQ    1

class Carte
{
  public:
    enum ValeurCarte
    {
        Oeuf,
        Poule,
        Renard,
        Coq,
    };
    Carte();
    Carte(ValeurCarte valeurCarte);
    ~Carte();
    unsigned int getValeurCarte() const;

  private:
    ValeurCarte valeurCarte;
};

#endif
