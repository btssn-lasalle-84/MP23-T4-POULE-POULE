#include "Carte.h"
#include <string>

Carte::Carte() : valeurCarte(0)
{
}

Carte::Carte(std::string symbole, unsigned int valeurCarte) :
                            symbole(symbole), valeurCarte(valeurCarte)
{
}

Carte::~Carte()
{
}