#include "Joueur.h"
#include <string>

Joueur::Joueur() : nomJoueur("")
{
}

Joueur::Joueur(std::string nomJoueur, unsigned int choixJoueur) :
    nomJoueur(nomJoueur), choixJoueur(choixJoueur)
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

unsigned int Joueur::getChoixJoueur() const
{
    return choixJoueur;
}

void Joueur::setChoixJoueur(unsigned int choixJoueur)
{
    this->choixJoueur = choixJoueur;
}