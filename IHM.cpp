#include "IHM.h"
#include "Carte.h"
#include "Joueur.h"
#include "MaitrePoulePoule.h"
#include <iostream>
#include <unistd.h>

std::string IHM::entreNomJoueur() const
{
    std::cout << "Pour commencer, veuillez entrer votre prénom : ";
    std::string nomJoueur;
    std::cin >> nomJoueur;
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
    std::cout << "Bienvenue sur la version " << NUMERO_VERSION
              << " du jeu du Poule-Poule !" << std::endl
              << std::endl;
}

void IHM::afficheMenu(std::string nomJoueur) const
{
    std::cout << "Que voulez-vous faire " << nomJoueur << " ?" << std::endl;
    std::cout << "[" << MaitrePoulePoule::ChoixMenu::JouePartie
              << "] Commencer une partie" << std::endl;
    std::cout << "[" << MaitrePoulePoule::ChoixMenu::Regles << "] Règles du jeu"
              << std::endl;
    std::cout << "[" << MaitrePoulePoule::ChoixMenu::QuitteJeu
              << "] Quitter le jeu" << std::endl;
}

void IHM::afficheRegles() const
{
    std::cout << "Voici les règles :" << std::endl;
    std::cout << "Tout d’abord, une partie se composera de " << NOMBRE_MANCHES
              << " manches." << std::endl;
    std::cout
      << "L’ordinateur sera le réalisateur, le Maître Poule Poule (MPP)."
      << std::endl;
    std::cout << "Le MPP va afficher successivement les cartes, une "
                 "par une. Une "
                 "fois affichées, ces cartes composeront le Film."
              << std::endl;
    std::cout << "Pendant ce temps, le joueur devra juste compter les "
                 "œufs ! Pour "
                 "une première partie, le paquet de cartes sera "
                 "composé de : "
              << NB_CARTES_OEUF << " œufs, " << NB_CARTES_POULE << " Poules, "
              << NB_CARTES_RENARD << " Renards, " << NB_CARTES_CANARD
              << " Canards, " << NB_CARTES_VER_DE_TERRE << " Vers de terre, "
              << NB_CARTES_OEUF_AUTRUCHE << "Oeufs d'autruche" << NB_CARTES_COQ
              << " Coq." << std::endl;
    std::cout << "Il faut savoir qu'une Poule couve un oeuf arrivé à "
                 "n'importe "
                 "quel moment de la manche."
              << std::endl;
    std::cout << "Le Renard chasse une Poule arrivée à n'importe quel "
                 "moment de la "
                 "manche."
              << std::endl;
    std::cout << "Le Canard n'est que de passage dans le film." << std::endl;
    std::cout
      << "Le Ver de terre attirera la prochaine poule, par conséquent elle "
         "ne couvrira pas d'oeufs."
      << std::endl;
    std::cout << "L'oeuf d'autruche compte pour deux oeufs, mais vu sa taille, "
                 "il ne peut pas être couvé par une poule."
              << std::endl;
    std::cout << "Le Coq met fin à la manche et vous devrez donner le nombre "
                 "d'oeufs que vous pensez avoir compter."
              << std::endl;
    std::cout << "Bonne chance !" << std::endl << std::endl;
}

void IHM::afficheCarte(const Carte& carte, const unsigned int numeroCarte) const
{
    temporiseCarte();
    effaceEcran();
    std::cout << "Carte numéro " << numeroCarte + 1 << std::endl;
    switch(carte.getValeurCarte())
    {
        case Carte::ValeurCarte::Oeuf:
            std::cout << R"(
             ________________________________________
            |                                        |
            |                                        |
            |                                        |
            |                                        |
            |                                        |
            |                  ████                  |
            |                ██░░░░██                |
            |              ██░░░░░░░░██              |
            |              ██░░░░░░░░██              |
            |            ██░░░░░░░░░░░░██            |
            |            ██░░░░░░░░░░░░██            |
            |            ██░░░░░░░░░░░░██            |
            |              ██░░░░░░░░██              |
            |                ████████                |
            |                                        |
            |                                        |
            |                                        |
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
        case Carte::ValeurCarte::Canard:
            std::cout << R"(
             ________________________________________
            |                                        |
            |                                        |
            |                                        |
            |          ..---..                       |
            |        .'  _    `.                     |
            |    __..'  (o)    :                     |
            |   `..__          ;                     |
            |         `.       /                     |
            |        ;      `..---...___             |
            |       .'                   `~-. .-')   |
            |      .                         ' _.'   |
            |       :                           :    |
            |       \                           '    |
            |       +                         J      |
            |       `._                   _.'        |
            |            `~--....___...---~'         |
            |                                        |
            |                                        |
            |________________________________________|
                                            )" << '\n';
            break;
        case Carte::ValeurCarte::VerDeTerre:
            std::cout << R"(
             ________________________________________
            |                                        |
            |                  .--.                  |
            |                 /  oo                  |
            |                /\_\_/                  |
            |               /\___/                   |
            |              ,`.__/                    |
            |              7___/                     |
            |              |___|                     |
            |              |___|                     |
            |               \___\_                   |
            |                \___\_                  |
            |                 \___\                  |
            |                  \___\                 |
            |                   \___\_               |
            |                    `.__\_              |
            |                      `._\              |
            |                         `\             |
            |                                        |
            |________________________________________|
                                            )" << '\n';
            break;
        case Carte::ValeurCarte::OeufAutruche:
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
        default:
            break;
    }
}

void IHM::afficheMessageDebutManche() const
{
    std::cout << "La manche va débuter..." << std::endl;
}

void IHM::afficheMessageFinPartie(unsigned int nbPointsJoueur) const
{
    std::cout << "Vous avez gagné " << nbPointsJoueur << " manche(s) sur "
              << NOMBRE_MANCHES << "." << std::endl
              << std::endl;
}

void IHM::finitFilm() const
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
    sleep(TEMPORISE_AFFICHAGE_COURT);
}

void IHM::temporiseAffichageMoyen() const
{
    sleep(TEMPORISE_AFFICHAGE_MOYEN);
}

void IHM::temporiseAffichageLong() const
{
    sleep(TEMPORISE_AFFICHAGE_LONG);
}

void IHM::quitteJeu() const
{
}