#include "IHM.h"
#include "Carte.h"
#include "Joueur.h"

#include <iostream>
#include <unistd.h>

std::string IHM::entreNomJoueur() const
{
    std::cout << "Pour commencer, veuillez entrer votre prénom : ";
    std::string nomJoueur;
    std::cin >> nomJoueur;
    temporiseAffichageCourt();
    effaceEcran();
    return nomJoueur;
}

unsigned int IHM::entreChoixJoueur() const
{
    std::cout << "Entrez votre réponse : ";
    unsigned int choixJoueur;
    std::cin >> choixJoueur;
    return choixJoueur;
}

unsigned int IHM::entreReponseNbOeufs() const
{
    unsigned int reponseNbOeuf;
    std::cin >> reponseNbOeuf;
    return reponseNbOeuf;
}

void IHM::afficheMessageBienvenue() const
{
    std::cout << "Bienvenue sur la version 1.1 du jeu du Poule-Poule !"
              << std::endl
              << std::endl;
}

void IHM::afficheMenu(std::string nomJoueur) const
{
    std::cout << "Que voulez-vous faire " << nomJoueur << " ?" << std::endl;
    std::cout << "[1] Commencer une partie" << std::endl;
    std::cout << "[2] Règles du jeu" << std::endl;
    std::cout << "[3] Quitter le jeu" << std::endl;
}

void IHM::afficheRegles() const
{
    std::cout << "Voici les règles :" << std::endl;
    std::cout << "Tout d’abord, l’ordinateur sera le réalisateur, le Maître "
                 "Poule Poule (MPP)."
              << std::endl;
    std::cout << "Le MPP va afficher successivement les cartes, une "
                 "par une. Une "
                 "fois affichées, ces cartes composeront le Film."
              << std::endl;
    std::cout << "Pendant ce temps, le joueur devra juste compter les "
                 "œufs !Pour "
                 "une première partie, le paquet de cartes sera "
                 "composé de : 15 "
                 "œufs, 10 Poules, 10 Renards et 1 Coq."
              << std::endl;
    std::cout << "Il faut savoir qu' une Poule couve un oeuf arrivé à "
                 "n' importe "
                 "quel moment de la partie."
              << std::endl;
    std::cout << "Le Renard chasse une Poule arrivée à n'importe quel "
                 "moment de la "
                 "partie."
              << std::endl
              << std::endl;
}

void IHM::afficheCarte(const Carte& carte) const
{
    temporiseCarte();
    switch(carte.getValeurCarte())
    {
        case Carte::ValeurCarte::Oeuf:
            std::cout << R"(
             ________________________________________
            |                                        |
            |                ████████                |
            |              ██        ██              |
            |            ██▒▒▒▒        ██            |
            |          ██▒▒▒▒▒▒      ▒▒▒▒██          |
            |          ██▒▒▒▒▒▒      ▒▒▒▒██          |
            |        ██  ▒▒▒▒        ▒▒▒▒▒▒██        |
            |        ██                ▒▒▒▒██        |
            |      ██▒▒      ▒▒▒▒▒▒          ██      |
            |      ██      ▒▒▒▒▒▒▒▒▒▒        ██      |
            |      ██      ▒▒▒▒▒▒▒▒▒▒    ▒▒▒▒██      |
            |      ██▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒██      |
            |        ██▒▒▒▒  ▒▒▒▒▒▒    ▒▒▒▒██        |
            |        ██▒▒▒▒            ▒▒▒▒██        |
            |          ██▒▒              ██          |
            |            ████        ████            |
            |                ████████                |
            |                                        |
            |________________________________________|
                                            )" << '\n';
            break;
        case Carte::ValeurCarte::Poule:
            std::cout << R"(
             ________________________________________
            |                                        |
            |           ,~.                          |
            |        ,-'__ `-,                       |
            |       {,-'  `. }              ,')      |
            |      ,( a )   `-.__         ,',')~,    |
            |     <=.) (         `-.__,==' ' ' '}    |
            |       (   )                      /     |
            |        `-'\   ,                  )     |
            |            |  \        `~.      /      |
            |            \   `._        \    /       |
            |             \     `._____,'   /        |
            |              `-.            ,'         |
            |                 `-.      ,-'           |
            |                    `~~~~'              |
            |                    //_||               |
            |                 __//--'/`              |
            |               ,--'/`  '                |
            |                  '                     |
            |________________________________________|
                                            )" << '\n';
            break;
        case Carte::ValeurCarte::Renard:
            std::cout << R"(
             ________________________________________
            |                                        |
            |                                        |
            |            ,-.      .-,                |
            |            |-.\ __ /.-|                |
            |            \  `    `  /                |
            |            / _     _  \                |
            |            | _`q  p _ |                |
            |            '._=/  \=_.'                |
            |              (`\()/`)`\                |
            |              (      )  \               |
            |              |(    )    \              |
            |              \ '--'   .- \             |
            |              |-      /    \            |
            |              | | | | |     |           |
            |              | | |.|.,..__ |           |
            |            .-""|`         `|           |
            |           /    |           /           |
            |           `-../____,..---'`            |
            |________________________________________|
                                            )" << '\n';
            break;
        case Carte::ValeurCarte::Coq:
            std::cout << R"(
             ________________________________________
            |                                        |
            |                                        |
            |                        ~-.             |
            |      ,,,,            ~-.~-.~-          |
            |     (.../           ~-.~-.~-.~-.~-.    |
            |     ) o~`,         ~-.~-.~-.~-.~-.~-.  |
            |     (/    \      ~-.~-.~-.~-.~-.~-.~-. |
            |      :    \    ~-.~-.~-.~-.~-.~-.~-.   |
            |     :     (_.~-.~-.~-.~-.~-.~-.~       |
            |    ::  .-~`    ~-.~-.~-.~-.~-.         |
            |   :.: :'    ._   ~-.~-.~-.~-.~-        |
            |    :::`-.    '-._  ~-.~-.~-.~-         |
            |     :::. `-.    '-,~-.~-.~-.           |
            |      ':::::.`''-.-'                    |
            |        '::::::,:'                      |
            |           '||"                         |
            |           / |                          |
            |         ~` ~"'                         |
            |________________________________________|
                                            )" << '\n';
            break;
        default:
            break;
    }
}

void IHM::afficheMessageDebutPartie() const
{
    std::cout << "La partie va débuter...";
}

void IHM::finiFilm() const
{
    temporiseAffichageMoyen();
    effaceEcran();

    std::cout << "Manche finie !" << std::endl;
    std::cout << "Saisissez le nombre d'oeufs que vous pensez avoir compté : ";
}

void IHM::gagnePartie(std::string nomJoueur) const
{
    std::cout << "Bravo " << nomJoueur << " ! Vous avez gagné la manche !"
              << std::endl
              << std::endl;
}

void IHM::perdPartie(std::string nomJoueur, unsigned int compteurOeufs) const
{
    std::cout << "Dommage " << nomJoueur << " tu as perdu ... " << std::endl;
    std::cout << "Le nombre d'oeuf(s) était de ";
    std::cout << compteurOeufs << std::endl << std::endl;
}

void IHM::effaceEcran() const
{
    system("clear");
}

void IHM::temporiseCarte() const
{
    sleep(TEMPS_DISTRIBUTION_CARTE);
}

void IHM::temporiseAffichageCourt() const
{
    sleep(1);
}

void IHM::temporiseAffichageMoyen() const
{
    sleep(2);
}

void IHM::quitteJeu() const
{
}