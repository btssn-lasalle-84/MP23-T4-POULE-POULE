#include "Joueur.h"
#include <string>

Joueur::Joueur() : nomJoueur("")
{
}

Joueur::Joueur(std::string  nomJoueur,
               unsigned int choixJoueur,
               unsigned int reponseNbOeuf) :
    nomJoueur(nomJoueur),
    choixJoueur(choixJoueur), reponseNbOeuf(reponseNbOeuf)
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

unsigned int Joueur::getReponseNbOeuf() const
{
    return reponseNbOeuf;
}

void Joueur::setReponseNbOeuf(unsigned int reponseNbOeuf)
{
    this->reponseNbOeuf = reponseNbOeuf;
}