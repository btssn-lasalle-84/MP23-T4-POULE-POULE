#include "Carte.h"
#include <string>

Carte::Carte() : valeurCarte()
{
}

Carte::Carte(std::string symbole, ValeurCarte valeurCarte) :
    symbole(symbole), valeurCarte(valeurCarte)
{
}

Carte::~Carte()
{
}