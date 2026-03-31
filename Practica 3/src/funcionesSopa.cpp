#include "funcionesSopa.h"
#include <string>

using namespace std;

void inicializarMatriz(matriz_sopa & matriz,const int fil, const int col)
{
	matriz = matriz_sopa(fil,col);
}

void liberaMatriz(matriz_sopa & matriz)
{
	matriz.~matriz_sopa();
}

void imprimeMatriz(const matriz_sopa & matriz)
{
	string resultado = "";
	for(int i = 0; i < matriz.getFil(); i++)
	{
		for(int j = 0; j < matriz.getCol(); i++)
			resultado += matriz.get(i,j) + " ";

		resultado += "\n";
	}
	cout << resultado;
}

void leerSopa(const string & ruta, matriz_sopa & matriz)
{
	matriz = matriz_sopa(ruta);
}

Direccion encuentraCoincidencias(const matriz_sopa & matriz, const string & palabra, int & fil_ini, int & col_ini, int & fil_fin, int & col_fin)
{
	//por si no se encuentra nada
	Direccion resultado = NOP;
	bool encontrado = false;

	for(int i = 0; i < matriz.getFil() && !encontrado; i++)
	{
		for(int j = 0; j < matriz.getCol() && !encontrado; j++)
		{
			if(matriz.get(i,j) == palabra[0])
			{
				fil_ini = fil_fin = i;
				col_ini = col_fin = j;

				const int MAX = 8; // maximas de iteraciones (dando la vuelta al rededor de la casilla actual)
				for(int d = 0; d < MAX; d++)
				{
					int dir_fil = 0, dir_col = 0;
					Direccion dirLocal = NOP;

					switch(d)
					{
						case 0: //Arriba
						{
							dirLocal = Arriba;
							dir_fil = -1;
							dir_col = 0;
							break;
						}
                                                case 1: // Abajo
                                                {
							dirLocal = Abajo;
							dir_fil = 1;
							dir_col = 0;
                                                        break;
                                                }
                                                case 2: // Derecha
                                                {
							dirLocal = Derecha;
							dir_fil = 0;
							dir_col = 1;
                                                        break;
                                                }
                                                case 3: // Izquierda
                                                {
							dirLocal = Izquierda;
							dir_fil = 0;
							dir_col = -1;
                                                        break;
                                                }
                                                case 4: // DArribaDer
                                                {
							dirLocal = DiagonalArribaDer;
							dir_fil = -1;
							dir_col = 1;
                                                        break;
                                                }
                                                case 5: // DAbajoDer
                                                {
                                                        dirLocal = DiagonalAbajoDer;
                                                        dir_fil = 1;
                                                        dir_col = 1;
                                                        break;
                                                }
                                                case 6: // DArribaIzq
                                                {
                                                        dirLocal = DiagonalArribaIzq;
                                                        dir_fil = -1;
                                                        dir_col = -1;
                                                        break;
                                                }
                                                case 7: // DAbajoIzq
                                                {
                                                        dirLocal = DiagonalAbajoIzq;
                                                        dir_fil = 1;
                                                        dir_col = -1;
                                                        break;
                                                }
					}

					bool correcto = true;
					int aux_i, aux_j;
					for(int k = 0; k < palabra.length() && correcto; k++)
					{
						// seguimos recorriendo en la direccion que hemos adoptado
						aux_i = i + dir_fil * k;
						aux_j = j + dir_col * k;

						if(aux_i < 0 || aux_i >= matriz.getFil() || aux_j < 0 || aux_j >= matriz.getCol() || matriz.get(aux_i,aux_j) != palabra[k])
							correcto = false;
					}

					if(correcto)
					{
						fil_fin = aux_i;
						col_fin = aux_j;
						resultado = dirLocal;
						encontrado = true;
					}
				}
			}
		}
	}

	return resultado;
}


