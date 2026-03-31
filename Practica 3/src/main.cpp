#include "Direcciones.h"
#include "funcionesSopa.h"
#include "funcionesPalabras.h"
#include <iostream>
#include <string>

using namespace std;

void BusquedaGlobal(vector_palabras & vector, matriz_sopa & matriz)
{
	for(int i = 0; i < vector.getOcupado(); i++)
	{
		int fil_ini,fil_fin,col_ini,col_fin;
		Direccion caso = encuentraCoincidencias(matriz,get(i,vector),fil_ini,col_ini,fil_fin,col_fin);
		cout << "Palabra: \t<Direccion> \t[i][j]INI \t[i][j]FIN" << endl;
		switch(caso)
		{
			case Arriba:
			{
				cout << get(i,vector) << ": \t<Arriba> \t[" << fil_ini << "][" << col_ini << "] \t[" << fil_fin << "][" << col_fin << "]";
                        	break;
			}
                        case Abajo:
                        {
                                cout << get(i,vector) << ": \t<Abajo> \t[" << fil_ini << "][" << col_ini << "] \t[" << fil_fin << "][" << col_fin << "]";
                        	break;
                        }
                        case Derecha:
                        {
                                cout << get(i,vector) << ": \t<Derecha> \t[" << fil_ini << "][" << col_ini << "] \t[" << fil_fin << "][" << col_fin << "]";
                        	break;
                        }
                        case Izquierda:
                        {
                                cout << get(i,vector) << ": \t<Izquierda> \t[" << fil_ini << "][" << col_ini << "] \t[" << fil_fin << "][" << col_fin << "]";
                        	break;
                        }
                        case DiagonalArribaDer:
                        {
                                cout << get(i,vector) << ": \t<DiagonalArribaDerecha> \t[" << fil_ini << "][" << col_ini << "] \t[" << fil_fin << "][" << col_fin << "]";
                        	break;
                        }
                        case DiagonalAbajoDer:
                        {
                                cout << get(i,vector) << ": \t<DiagonalAbajoDerecha> \t[" << fil_ini << "][" << col_ini << "] \t[" << fil_fin << "][" << col_fin << "]";
                        	break;
                        }
                        case DiagonalArribaIzq:
                        {
                                cout << get(i,vector) << ": \t<DiagonalArribaIzquierda> \t[" << fil_ini << "][" << col_ini << "] \t[" << fil_fin << "][" << col_fin << "]";
                        	break;
                        }
                        case DiagonalAbajoIzq:
                        {
                                cout << get(i,vector) << ": \t<DiagonalAbajoIzquierda> \t[" << fil_ini << "][" << col_ini << "] \t[" << fil_fin << "][" << col_fin << "]";
                        	break;
			}
                        default:
                        {
                                cout << get(i,vector) << ": \t<NoEncontrada> \t[-1][-1] \t[-1][-1]";
				break;
                        }

		}
	}
}

int main(int argc, char *argv[])
{
	if(argc != 5)
	{
		cerr << "Error en el uso del programa\n";
		cerr << "Uso: " << argv[0] << "-[flag] <fichero> -[flag] <ruta>\n";
		cerr << "\tFlags: \n\t\t-s: Paso de la matriz\n\t\t-p: Paso de las palabras a buscar" << endl;

		return 1;
	}

	matriz_sopa SopaDeLetras;
	vector_palabras Palabras;

	for(int i = 1; i < 5; i++)
	{
		if(argv[i] == "-s")
			leerSopa(argv[i+1],SopaDeLetras);
		if(argv[i] == "-p")
			leerPalabras(argv[i+1],Palabras);
	}

	imprimirPalabras(Palabras);
	cout << endl;
	imprimeMatriz(SopaDeLetras);
	cout << endl;

	BusquedaGlobal(Palabras,SopaDeLetras);

	return 0;
}
