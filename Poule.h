#ifndef POULE_H
#define POULE_H

#include <iostream>
#include <string>

class Poule : public Carte
{
    private:
        unsigned int nbCartesPoule;

    public:
        Poule();
        Poule(unsigned int nbCartesPoule = 10);
};

#endif // POULE_H