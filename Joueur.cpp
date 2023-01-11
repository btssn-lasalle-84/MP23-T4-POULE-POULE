#include "Joueur.h"
#include <string>

Joueur::Joueur() : nomJoueur("")
{
}

Joueur::Joueur(std::string nomJoueur) : nomJoueur(nomJoueur)
{
}

std::string Joueur::getNomJoueur() const
{
    return nomJoueur;
}

void Joueur::setNomJoueur(std::string nomJoueur)
{
    this->nomJoueur = nomJoueur;
}