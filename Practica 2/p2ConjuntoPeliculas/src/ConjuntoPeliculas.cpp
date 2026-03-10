/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ConjuntoPeliculas.cpp
 * Author: Aaron López Molino
 * 
 * Created on 26 de septiembre de 2022, 11:59
 */

#include "ConjuntoPeliculas.h"

ConjuntoPeliculas::ConjuntoPeliculas()
{
	conj = new Pelicula[reservado];
	numpeliculas = 0;
}

ConjuntoPeliculas::ConjuntoPeliculas(const ConjuntoPeliculas& orig)
{
	conj = orig.conj;
	numpeliculas = orig.numpeliculas;
}

ConjuntoPeliculas::~ConjuntoPeliculas()
{
	delete[] conj;
	numpeliculas = 0;
}

void ConjuntoPeliculas::leerFichero(string rutaFichero, int numdatos)
{
	for(int i = 0; i < numdatos; i++)
	{
		
	}
}

void ConjuntoPeliculas::aniadePelicula(int newid, string newnombre, int newanio,float newvaloracion, string newgenero)
{
	if(numpeliculas == reservado)
		resize();

	conj[numpeliculas] = Pelicula(newid,newnombre,newanio,newvaloracion,newgenero);
	numpeliculas++;
}

void ConjuntoPeliculas::borrar(int id)
{
	int pos = buscar(id);
	if(pos != -1)
	{
		Pelicula aux = conj[numpeliculas];
		conj[pos] = conj[numpeliculas];
		conj[pos] = aux;

		numpeliculas--;
	}
}

Pelicula ConjuntoPeliculas::at(int id) const
{
	Pelicula result;

	int pos = buscar(id);

	if(pos != -1 && pos >= 0 && pos < reservado)
		result = conj[pos];

	return result;
}

void ConjuntoPeliculas::ordenaporranking()
{
	int j;
	Pelicula aux;

	for (int i = 1; i < numpeliculas; i++) {
        	aux = conj[i];
        	j = i - 1;

        	while (j >= 0 && conj[j].getValoracion() > aux.getValoracion())
		{
        		conj[j + 1] = conj[j];
        	    	j = j - 1;
        	}

        	conj[j + 1] = aux;
    	}
}

string ConjuntoPeliculas::to_string() const
{
	string result = "";
	for(int i = 0; i < numpeliculas; i++)
		result += conj[i].to_string();

	return result;
}

void ConjuntoPeliculas::escribeFichero(string rutaFichero) const
{

}

void ConjuntoPeliculas::clear()
{
	/**
		for(int i = 0; i < numpeliculas; i++)
			conj[i] = Pelicula();
	*/

	delete[] conj;
	conj = new Pelicula[reservado];

	numpeliculas = 0;
}

void ConjuntoPeliculas::resize()
{
	if(numpeliculas == reservado)
	{
		Pelicula * aux = new Pelicula[reservado];
		for(int i = 0; i < reservado; ++i)
			aux[i] = conj[i];

		delete[] conj;
		conj = new Pelicula[reservado * 2];

		for(int i = 0; i < reservado; i++)
			conj[i] = aux[i];

		delete[] aux;
		reservado *= 2;
	}
}

int ConjuntoPeliculas::buscar(const int id) const
{
	int pos = -1;
	for(int i = 0; i < numpeliculas && pos == -1; i++)
	{
		if(conj[i].getId() == id)
			pos = i;
	}

	return pos;
}
