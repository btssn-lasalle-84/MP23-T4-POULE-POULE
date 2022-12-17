#ifndef OEUF_H
#define OEUF_H

#include <iostream>

class Oeuf : public Carte
{
    private:
        unsigned int nbCartesOeuf;

    public:
        Oeuf();
        Oeuf(unsigned int nbCartesOeuf = 15);
};

#endif // OEUF_H