#include <iostream>
#include "Par.h"
#include "VectorPares.h"

using namespace std;

int main()
{
    //ejemplos para prueba
    Par prueba1(4,5);
    Par prueba2(6,6);
    Par prueba3;
    prueba3 = suma(prueba1,prueba2);
    prueba3.mostrar();

    //ejemplos para vectorpares
    VectorPares prueb;

    for(int i = 0; i < 10; i++){
        Par newpar(i,i+5);
        prueb.anaide(newpar);
    }
    Par modificapar(10,10);
    prueb.modifica(3,modificapar);
    prueb.imprime();
}
