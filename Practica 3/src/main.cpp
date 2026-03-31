#include "Direcciones.h"
#include "funcionesSopa.h"
#include "funcionesPalabras.h"
#include <iostream>
#include <string>

using namespace std;

void BusquedaGlobal(vector_palabras & vector, matriz_sopa & matriz)
{
	cout << "Palabra: \t\t<Direccion> \t\t[i][j]INI \t\t[i][j]FIN\n" << endl;
	for(int i = 0; i < vector.getOcupado(); i++)
	{
		int fil_ini,fil_fin,col_ini,col_fin;
		Direccion caso = encuentraCoincidencias(matriz,get(i,vector),fil_ini,col_ini,fil_fin,col_fin);
		switch(caso)
		{
			case Arriba:
			{
				cout << get(i,vector) << ": \t\t<Arriba> \t\t\t[" << fil_ini << "][" << col_ini << "] \t\t\t[" << fil_fin << "][" << col_fin << "]" << endl;
                        	break;
			}
                        case Abajo:
                        {
                                cout << get(i,vector) << ": \t\t<Abajo> \t\t\t[" << fil_ini << "][" << col_ini << "] \t\t\t[" << fil_fin << "][" << col_fin << "]" << endl;
                        	break;
                        }
                        case Derecha:
                        {
                                cout << get(i,vector) << ": \t\t<Derecha> \t\t\t[" << fil_ini << "][" << col_ini << "] \t\t\t[" << fil_fin << "][" << col_fin << "]" << endl;
                        	break;
                        }
                        case Izquierda:
                        {
                                cout << get(i,vector) << ": \t\t<Izquierda> \t\t\t[" << fil_ini << "][" << col_ini << "] \t\t\t[" << fil_fin << "][" << col_fin << "]" << endl;
                        	break;
                        }
                        case DiagonalArribaDer:
                        {
                                cout << get(i,vector) << ": \t\t<DiagonalArribaDerecha> \t[" << fil_ini << "][" << col_ini << "] \t\t\t[" << fil_fin << "][" << col_fin << "]" << endl;
                        	break;
                        }
                        case DiagonalAbajoDer:
                        {
                                cout << get(i,vector) << ": \t\t<DiagonalAbajoDerecha> \t\t[" << fil_ini << "][" << col_ini << "] \t\t\t[" << fil_fin << "][" << col_fin << "]" << endl;
                        	break;
                        }
                        case DiagonalArribaIzq:
                        {
                                cout << get(i,vector) << ": \t\t<DiagonalArribaIzquierda> \t[" << fil_ini << "][" << col_ini << "] \t\t\t[" << fil_fin << "][" << col_fin << "]" << endl;
                        	break;
                        }
                        case DiagonalAbajoIzq:
                        {
                                cout << get(i,vector) << ": \t\t<DiagonalAbajoIzquierda> \t[" << fil_ini << "][" << col_ini << "] \t\t\t[" << fil_fin << "][" << col_fin << "]" << endl;
                        	break;
			}
                        default:
                        {
                                cout << get(i,vector) << ": \t\t<NoEncontrada> \t\t\t[-1][-1] \t\t[-1][-1]" << endl;
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

	for(int i = 1; i < 4; i++)
	{
		string flag = argv[i];
		if(flag == "-s")
		{
			string ruta = argv[i+1];
			leerSopa(ruta,SopaDeLetras);
		}
		else if(flag == "-p")
		{
			string ruta = argv[i+1];
			leerPalabras(ruta,Palabras);
		}
	}

	imprimirPalabras(Palabras);
	cout << endl;

	imprimeMatriz(SopaDeLetras);
	cout << endl;

	BusquedaGlobal(Palabras,SopaDeLetras);

	return 0;
}
