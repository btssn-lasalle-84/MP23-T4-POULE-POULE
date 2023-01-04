#include "Joueur.h"
#include <string>

using namespace std;

Joueur::Joueur() : nomJoueur(" ")
{
}

Joueur::Joueur(string nomJoueur) : nomJoueur(nomJoueur)
{
}

std::string Joueur::getNomJoueur() const
{
    return nomJoueur;
}