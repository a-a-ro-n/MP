#ifndef VECTORPARES_H
#define VECTORPARES_H

#include "Par.h"

class VectorPares
{
    public:
        VectorPares();
        Par at(int i);
        void modifica(int i, Par newpar);
        void imprime();
        void anaide(Par newpar);
        int tamanioactual();

    private:
    const int MAX = 100;
    int tam = 0;
    Par pares[100];
};

#endif // VECTORPARES_H
