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
#include <fstream>
#include <string>

ConjuntoPeliculas::ConjuntoPeliculas()
{
	conj = new Pelicula[reservado];
	numpeliculas = 0;
}

ConjuntoPeliculas::ConjuntoPeliculas(const ConjuntoPeliculas& orig)
{
	reservado = orig.reservado;
	conj = new Pelicula[reservado];

	numpeliculas = orig.numpeliculas;

	for(int i = 0; i < numpeliculas; i++)
		conj[i] = orig.conj[i];
}

ConjuntoPeliculas::~ConjuntoPeliculas()
{
	delete[] conj;
	numpeliculas = 0;
}

void ConjuntoPeliculas::leerFichero(string rutaFichero, int numdatos) {
	ifstream archivo(rutaFichero);
    	string dato, omitir;

    	if(archivo.is_open())
	{
        	// 1. Saltamos la cabecera completa
        	getline(archivo, omitir);

        	// 2. Limpiamos y preparamos el conjunto
        	if(conj != nullptr)
        		delete[] conj;

        	reservado = numdatos;
        	numpeliculas = 0;
        	conj = new Pelicula[reservado];

        	bool fin_archivo = false;

        	for(int i = 0; i < numdatos && !fin_archivo; i++)
		{

            		if(getline(archivo, dato, ';'))
			{

                		if(dato != "" && dato != "\n" && dato != "\r") {
                    		int id = stoi(dato);

                    		getline(archivo, dato, ';');
                    		string nombre = dato;

                    		getline(archivo, dato, ';');
                    		int anio = stoi(dato);

                    		getline(archivo, dato);
                    		for(int j = 0; j < dato.length(); j++)
                    			if(dato[j] == ',') dato[j] = '.';
                    		float valoracion = stof(dato);

                    		aniadePelicula(id, nombre, anio, valoracion, "");
              		}
			else // linea vacia
				i--;
    			}
			else
     				fin_archivo = true;
		}
		archivo.close();
    	}
	else
        	cout << "No se pudo abrir el archivo." << endl;
}

void ConjuntoPeliculas::aniadePelicula(int newid, string newnombre, int newanio,float newvaloracion, string newgenero)
{
	if(numpeliculas == reservado)
		resize();

	conj[numpeliculas] = Pelicula(newid,newnombre,newanio,newvaloracion,newgenero);
	numpeliculas++;
}

void ConjuntoPeliculas::borrar(int id) {
    int pos = buscar(id);

    if (pos != -1)
    {
        conj[pos] = conj[numpeliculas - 1]; 
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
    	ofstream archivo(rutaFichero);
    	if(archivo)
	{
        	archivo << ";Movie title;Released Year;ImDb Rating" << endl;
       		for(int i = 0; i < numpeliculas; i++)
		{
            		archivo << conj[i].getId() << ";" << conj[i].getNombre() << ";" << conj[i].getAnio() << ";";
	            	string nota_str = std::to_string(conj[i].getValoracion());
            		for(int j=0; j < nota_str.length(); j++)
                		if(nota_str[j] == '.') nota_str[j] = ',';

			archivo << nota_str << endl;
        	}
       	archivo.close();
    	}
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
		if(reservado == 0)
		{
			reservado = 10; // establecemos un reservado

			if(conj) // si el conjunto no esta vacio por algun motivo extraño lo borramos
				delete[] conj;

			conj = new Pelicula[reservado]; // asignamos al conjunto un espacio de reservado
		}

		else
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
