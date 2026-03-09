/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pelicula.cpp
 * 
 */

#include "Pelicula.h"

Pelicula::Pelicula()
{
	id = -1;
	nombre = "";
	anio = -1;
	valoracion = -1;
	genero = "";
}

Pelicula::Pelicula(int newid, string newnombre, int newanio, float newvaloracion, string newgenero)
{
	id = newid;
        nombre = newnombre;
        anio = newanio;
        valoracion = newvaloracion;
        genero = newgenero;
}

Pelicula::Pelicula(const Pelicula& orig)
{
	id = orig.id;
	nombre = orig.nombre;
	anio = orig.anio;
	valoracion = orig.valoracion
	genero = orig.genero;
}

string Pelicula::to_string() const
{
	return "" + id + " " + nombre + " " + anio + " " + valoracion + " " + genero + "\n";
}

int & Pelicula::setId()
{
	return id;
}

string & Pelicula::setNombre()
{
	return nombre;
}

float & Pelicula::setValoracion()
{
	return valoracion;
}

string & Pelicula::setGenero()
{
	return genero;
}

int & Pelicula::setAnio()
{
	return anio;
}

Pelicula::~Pelicula() {

}

int Pelicula::getId() const
{
	return id;
}

string Pelicula::getNombre() const
{
	return nombre;
}

string Pelicula::getGenero() const
{
	return genero
}

int Pelicula::getAnio() const
{
	return anio;
}

float Pelicula::getValoracion() const
{
	return valoracion;
}
