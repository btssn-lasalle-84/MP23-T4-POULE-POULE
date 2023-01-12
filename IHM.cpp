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
    return nomJoueur;
}

void IHM::afficheMenu() const
{
    std::cout << "Bienvenue sur le jeu du Poule-Poule !" << std::endl;
    std::cout << "[1] Commencer une partie" << std::endl;
    std::cout << "[2] Règles du jeu" << std::endl;
}

unsigned int IHM::entreChoixJoueur() const
{
    std::cout << "Entrez votre réponse : ";
    unsigned int choixJoueur;
    std::cin >> choixJoueur;
    return choixJoueur;
}

void IHM::afficheRegles() const
{
    std::cout << "Voici les règles" << std::endl;
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
              << std::endl;

    std::cout << "Appuyez sur [1] afin de revenir au menu principal"
              << std::endl;
}

void IHM::afficheCarte(const Carte& carte) const
{
    system("clear");
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
                    sleep(TEMPS_DISTRIBUTION_CARTE);
                    
                    break;

        case Carte::ValeurCarte::Poule:
                    std::cout << R"(
                     ________________________________________
                    |                                        |
                    |           ,~.                          |
                    |        ,-'__ `-,                       |
                    |       |,-'  `. |              ,')      |
                    |      ,( a )   `-.__         ,',')~,    |
                    |     <=.) (         `-.__,==' ' ' '|    |
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
                    sleep(TEMPS_DISTRIBUTION_CARTE);
                    
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
                    sleep(TEMPS_DISTRIBUTION_CARTE);
                    
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
                    |     :     {_.~-.~-.~-.~-.~-.~-.~       |
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
                    sleep(TEMPS_DISTRIBUTION_CARTE);
                
                break;

                default:
                    break;
    }
    }

void IHM::finManche()
{
    sleep(2);
    system("clear");

    std::cout << "Manche finie !" << std::endl;
    std::cout << "Saisissez le nombre d'oeufs que vous pensez avoir compter : ";
}

unsigned int IHM::entreReponseNbOeufs() const
{
    unsigned int reponseNbOeuf;
    std::cin >> reponseNbOeuf;
    return reponseNbOeuf;
}

void IHM::gagnePartie()
{
    std::cout << "Bravo ! Vous avez gagné la manche !" << std::endl;
}

void IHM::perduPartie()
{
    std::cout << "Perdu... dommage..." << std::endl;
}
