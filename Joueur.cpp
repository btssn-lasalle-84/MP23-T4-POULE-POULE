#include "Joueur.h"
#include <string>

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