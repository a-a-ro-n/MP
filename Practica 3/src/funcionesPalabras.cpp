#include "funcionesPalabras.h"
#include <fstream>
#include <string>

using namespace std;

void leerPalabras(const string & ruta, vector_palabras & vector)
{
	ifstream archivo(ruta);
	if(archivo.is_open())
	{
		string dato;
		getline(archivo,dato);
		int palabras = stoi(dato);
		vector = vector_palabras(palabras);

		for(int i = 0; i < palabras; i++)
		{
			getline(archivo, dato);
			vector.aniade(dato);
		}
	}
	else
		cerr << "Error al abrir el fichero " << ruta << endl;
}

string get(const int index,vector_palabras & vector)
{
	return vector.get(index);
}

void imprimirPalabras(vector_palabras & vector)
{
	string resultado = "";
	for(int i = 0; i < vector.getOcupado(); i++)
		resultado += vector.get(i) + "\t";

	cout << resultado << endl;
}
