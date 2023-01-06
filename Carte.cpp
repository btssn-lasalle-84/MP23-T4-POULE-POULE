#include "Carte.h"
#include <string>

Carte::Carte() : valeurCarte()
{
}

Carte::Carte(ValeurCarte valeurCarte) : valeurCarte(valeurCarte)
{
}

Carte::~Carte()
{
}

unsigned int Carte::getValeurCarte() const
{
    return valeurCarte;
}