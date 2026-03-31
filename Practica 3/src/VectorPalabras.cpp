#include "VectorPalabras.h"

using namespace std;

vector_palabras::vector_palabras()
{
	ocupado = reserva = 0;
	vector = nullptr;
}

vector_palabras::vector_palabras(const int _reserva)
{
	reserva = _reserva;
	ocupado = 0;
	vector = new string[reserva];
}

vector_palabras::vector_palabras(const vector_palabras & _vector)
{
	reserva = _vector.reserva;
	ocupado = _vector.ocupado;
	vector = new string[reserva];

	for(int i = 0; i < ocupado; i++)
		vector[i] = _vector.vector[i];
}

vector_palabras::~vector_palabras()
{
	if(vector)
		delete[] vector;
	reserva = ocupado = 0;
	vector = nullptr;
}

void vector_palabras::aniade(const string & palabra)
{
	if(ocupado == reserva)
		resize();
	else
	{
		vector[ocupado] = palabra;
		ocupado++;
	}
}

void vector_palabras::resize()
{
	if(ocupado == reserva)
	{
		string * aux = new string[reserva];
		for(int i = 0; i < reserva; i++)
			aux[i] = vector[i];

		if(vector)
			delete[] vector;

		if(reserva == 0)
			reserva = 10;
		else
			reserva *= 2;

		vector = new string[reserva];
		for(int i = 0; i < ocupado; i++)
			vector[i] = aux[i];

		delete[] aux;
	}
}

int vector_palabras::getOcupado() const
{
	return ocupado;
}

string vector_palabras::get(const int index) const
{
	string result = "";

	if(!(index < 0 || index >= ocupado))
		result = vector[index];

	return result;
}
