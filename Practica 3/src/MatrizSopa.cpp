#include <fstream>
#include "MatrizSopa.h"
#include <string>

using namespace std;

matriz_sopa::matriz_sopa()
{
	fil = col = 0;
	matriz = nullptr;
}

matriz_sopa::matriz_sopa(const int _fil,const int _col)
{
	fil = _fil;
	col = _col;
	matriz = new char *[fil];
	for(int i = 0 ; i < fil; i++)
		matriz[i] = new char[col];
}

matriz_sopa::matriz_sopa(const matriz_sopa & _matriz)
{
	fil = _matriz.fil;
	col = _matriz.col;
        matriz = new char *[fil];
        for(int i = 0 ; i < fil; i++)
                matriz[i] = new char[col];

	for(int i = 0; i < fil; i++)
	{
		for(int j = 0; j < col; j++)
			matriz[i][j] = _matriz.matriz[i][j];
	}
}

matriz_sopa::matriz_sopa(const string & ruta)
{
        ifstream archivo(ruta);

        matriz = nullptr;
        fil = col = 0;

        if(archivo.is_open())
        {
                string dato;

                if(getline(archivo, dato))
                        fil = stoi(dato);

                if(getline(archivo, dato))
                        col = stoi(dato);

                matriz = new char *[fil];
                for(int i = 0 ; i < fil; i++)
                        matriz[i] = new char[col];

                for(int i = 0; i < fil; i++)
                        for(int j = 0; j < col; j++)
                                archivo >> matriz[i][j];

                archivo.close();
        }
        else
                cerr << "Error: No se pudo abrir el archivo " << ruta << endl;
}

matriz_sopa & matriz_sopa::operator=(const matriz_sopa & _matriz)
{
	if(this != &_matriz)
	{
		if(matriz)
		{
			for(int i = 0; i < fil; i++)
				delete[] matriz[i];

			delete[] matriz;
		}

		fil = _matriz.fil;
		col = _matriz.col;

		if(fil > 0 && col > 0)
		{
			matriz = new char *[fil];
			for(int i = 0 ; i < fil; i++)
				matriz[i] = new char[col];

			for(int i = 0; i < fil; i++)
			{
				for(int j = 0; j < col; j++)
					matriz[i][j] = _matriz.matriz[i][j];
			}
		}
		else
			matriz = nullptr;
	}
	return *this;
}

matriz_sopa::~matriz_sopa()
{
	if(matriz)
	{
		for(int i = 0; i < fil; i++)
			delete[] matriz[i];

		delete[] matriz;
	}

	fil = col = 0;
	matriz = nullptr;
}


int matriz_sopa::getFil() const
{
	return fil;
}

int matriz_sopa::getCol() const
{
	return col;
}

char matriz_sopa::get(const int _fil, const int _col) const
{
	char result = '\0';

	if(!(_fil < 0 || _fil >= fil) && !(_col < 0 || _col >= col))
		result = matriz[_fil][_col];

	return result;
}
