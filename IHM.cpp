#include "IHM.h"

#include <iostream>
#include <unistd.h>

void IHM::afficheMenu()
{
    std::cout << "Bienvenue sur le jeu du Poule-Poule !" << std::endl;
    std::cout << "[1] Commencer une partie" << std::endl;
    std::cout << "[2] Règles du jeu" << std::endl;
    std::cin >> choixJoueur;

    if(choixJoueur == 1)
    {
        system("clear");
        demarrePartie();
    }
    else if(choixJoueur == 2)
    {
        system("clear");
        afficheRegles();
    }
    else
    {
        std::cout << "Veuillez entrer une valeur correcte !" << std::endl;
        sleep(3);
        system("clear");
        afficheMenu();
    }
}

void IHM::demarrePartie()
{
    std::cout << "Veuillez entrer votre prénom : ";
    std::cin >> nomJoueur;
    std::cout << "Etes-vous prêt " << nomJoueur << " ? La partie va débuter"
              << std::endl;

    sleep(3);
    system("clear");
    deroulementPartie();
}

void IHM::afficheRegles()
{
    std::cout << "Tout d’abord, l’ordinateur sera le réalisateur, le Maître de "
                 "Poule Poule(MPP)."
              << std::endl;
    std::cout
      << "Le MPP va afficher successivement les cartes, une par une. Une "
         "fois affichées, ces cartes composeront le Film."
      << std::endl;
    std::cout
      << "Pendant ce temps, le joueur devra juste compter les œufs !Pour "
         "une première partie, le paquet de cartes sera composé de : 15 "
         "œufs, 10 Poules, 10 Renards et 1 Coq."
      << std::endl;
    std::cout
      << "Il faut savoir qu' une Poule couve un oeuf arrivé à n' importe "
         "quel moment de la partie."
      << std::endl;
    std::cout
      << "Le Renard chasse une Poule arrivée à n'importe quel moment de la "
         "partie."
      << std::endl;

    std::cout << "Appuyez sur [1] afin de revenir au menu principal"
              << std::endl;
    std::cin >> choixJoueur;

    while(choixJoueur != 1)
    {
        std::cout << "Veuillez entrer [1]" << std::endl;
        std::cin >> choixJoueur;
    }
    system("clear");
    afficheMenu();
}

void IHM::deroulementPartie()
{
    while(compteurOeuf != 5)
    {
        switch(carteTiree)
        {
            case 1:
                if(carteTiree == 0)
                {
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
                    system("clear");
                    compteurOeuf = compteurOeuf + 1;
                }

            case 2:
                if(carteTiree == 1)
                {
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
                    sleep(TEMPS_DISTRIBUTION_CARTE);
                    system("clear");
                    compteurOeuf      = compteurOeuf - 1;
                    compteurOeufCouve = compteurOeufCouve + 1;
                }

            case 3:
                if(carteTiree == 2)
                {
                    sleep(TEMPS_DISTRIBUTION_CARTE);
                    system("clear");

                    compteurOeufCouve = compteurOeufCouve - 1;
                    compteurOeuf      = compteurOeuf + 1;
                }

            case 4:
                if(carteTiree == 3)
                {
                    sleep(2);
                    system("clear");

                    std::cout << "Manche finie !" << std::endl;
                    std::cout << "Saisissez le nombre d'oeufs que vous "
                                 "pensez avoir "
                                 "compter : ";
                    std::cin >> reponseJoueur;

                    if(reponseJoueur == compteurOeuf)
                    {
                        std::cout << "Bravo ! Vous avez gagné la manche !"
                                  << std::endl;
                        sleep(5);
                        system("clear");
                        afficheMenu();
                    }
                    else
                    {
                        std::cout << "Perdu... dommage..." << std::endl;
                        sleep(5);
                        system("clear");
                        afficheMenu();
                    }

                    break;
                }

            case 5:
                if(compteurOeuf == 5)
                {
                    std::cout << "La manche est terminée, le nombre d'oeuf "
                                 "est égal "
                                 "à 5."
                              << std::endl;
                }
        }
    }
}