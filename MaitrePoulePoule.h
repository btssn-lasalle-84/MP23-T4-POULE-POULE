#ifndef MAITREPOULEPOULE_H
#define MAITREPOULEPOULE_H

#include <string>
#include <vector>
#include "Carte.h"

//#define DEBUG_MAITREPOULEPOULE

#define NUMERO_VERSION 2.1
#define NOMBRE_MANCHES 3

class Carte;
class Joueur;
class IHM;

class MaitrePoulePoule
{
  private:
    Joueur*            monJoueur;
    IHM*               monIHM;
    std::vector<Carte> paquetCartes;
    unsigned int       nbPointsJoueur;
    unsigned int       compteurOeufs;
    unsigned int       compteurOeufsCouves;
    unsigned int       compteurVersDeTerre;
    unsigned int       compteurOeufsAutruche;

    void               derouleFilm();
    void               reinitialiseCompteurs();
    void               reinitialiseNbPointsJoueur();
    void               distribueCartes();
    bool               estPartieFinie(const Carte& carte) const;
    std::vector<Carte> creeCartesOeuf();
    std::vector<Carte> creeCartesPoule();
    std::vector<Carte> creeCartesRenard();
    std::vector<Carte> creeCartesCoq();
    std::vector<Carte> creeCartesCanard();
    std::vector<Carte> creeCartesVerDeTerre();
    std::vector<Carte> creeCartesOeufAutruche();
    std::vector<Carte> creeCartesFermier();
    void               creePaquetCartes();
    void               melangePaquet();
    void               compteNbOeufs(const Carte& carte);
    void               convertitOeufAutrucheEnOeuf();
    bool               verifieReponseJoueur() const;
    bool               gereChoix(unsigned int choix);

  public:
    enum ChoixMenu
    {
        Indefini,
        JouePartie,
        Regles,
        QuitteJeu,
    };
    MaitrePoulePoule();
    ~MaitrePoulePoule();
    void         jouePartie();
    unsigned int getCompteurOeufs() const;
    void         setCompteurOeufs(unsigned int compteurOeufs);
    unsigned int getNbPointsJoueur() const;
};

#endif // MAITREPOULEPOULE_H