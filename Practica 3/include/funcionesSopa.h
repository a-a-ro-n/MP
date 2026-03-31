#include "MatrizSopa.h"
#include "Direcciones.h"

void inicializarMatriz(matriz_sopa & matriz,const int, const int);
void liberaMatriz(matriz_sopa &);
void imprimeMatriz(const matriz_sopa &);
void leerSopa(const string &, matriz_sopa &);
Direccion encuentraCoincidencias(const matriz_sopa &, const string &,int &,int &,int &,int &);
