/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Usuario.cpp
 * Author: Aaron López Molino
 * 
 * Created on 8 de noviembre de 2022, 11:09
 */

#include "Usuario.h"
#include <iostream>
#include <string>

using namespace std;

/*
private:
    string correoelectronico;
    string nombreusuario;
    int id;
    int numpeliculas;
    int * idAmigos;
    int numAmigos;
    int numreservadoAmigos;
    static const int INCREMENTO = 5;
*/

Usuario::Usuario() {
	id = -1;

	correoelectronico = nombreusuario = "";

 	numpeliculas = numAmigos = 0;

	idAmigos = new int[INCREMENTO];
	numreservadoAmigos = INCREMENTO;
}

Usuario::Usuario(const Usuario& orig) {
	id = orig.id; // debe de ser unico pero estoy haciendo una copia PREGUNTAR!!!!!

	correoelectronico = orig.correoelectronico;
	nombreusuario = orig.nombreusuario;

   	numpeliculas = orig.numpeliculas;
	numAmigos = orig.numAmigos;

	numreservadoAmigos = orig.numreservadoAmigos;

	idAmigos = new int[numreservadoAmigos];

	for(int i = 0; i < numreservadoAmigos; i++)
		idAmigos[i] = orig.idAmigos[i];
}

Usuario::~Usuario() {
	if(idAmigos)
		delete[] idAmigos;

        correoelectronico = nombreusuario = "";
	numpeliculas = numAmigos = numreservadoAmigos = 0;
}

string Usuario::getCorreoElectronico(){
  	return correoelectronico;
}

string Usuario::getNombreUsuario(){
   	return nombreusuario;
}

int Usuario::getId(){
   	return id;
}
string & Usuario::putNombreUsuario(){
   	return nombreusuario;
}

string & Usuario::putCorreoElectronico(){
   	return correoelectronico;
}

Usuario::Usuario(int newid, string newnombreusuario, string newcorreoelectronico){
  	id = newid;
	nombreusuario = newnombreusuario;
	correoelectronico = newcorreoelectronico;

	numpeliculas = numAmigos = 0;
	numreservadoAmigos = INCREMENTO;
	idAmigos = new int[INCREMENTO];
}

int & Usuario::setId(){
  	return id;
}

Usuario & Usuario::operator=(const Usuario & orig){
   	if(this != &orig)
	{
		if(idAmigos)
			delete[] idAmigos;

		id = orig.id;

        	correoelectronico = orig.correoelectronico;
        	nombreusuario = orig.nombreusuario;

        	numpeliculas = orig.numpeliculas;
        	numAmigos = orig.numAmigos;

        	numreservadoAmigos = orig.numreservadoAmigos;

        	idAmigos = new int[numreservadoAmigos];

        	for(int i = 0; i < numreservadoAmigos; i++)
                	idAmigos[i] = orig.idAmigos[i];

	}

	return *this;
}

int Usuario::getNumPeliculas() const{
   	return numpeliculas;
}

void Usuario::resize()
{
	if(numreservadoAmigos == numAmigos)
	{
		if(numAmigos == 0)
		{
			numreservadoAmigos = INCREMENTO;
			idAmigos = new int[numreservadoAmigos];
		}
		else
		{
			int * aux = new int[numreservadoAmigos];
			for(int i = 0; i < numAmigos; i++)
				aux[i] = idAmigos[i];

			if(idAmigos)
				delete[] idAmigos;

			numreservadoAmigos += INCREMENTO;
			idAmigos = new int[numreservadoAmigos];

			for(int i = 0; i < numAmigos; i++)
				idAmigos[i] = aux[i];

			if(aux)
				delete[] aux;
		}
	}
}

bool Usuario::anaideAmigo(int idnuevoamigo){
	if(numAmigos == numreservadoAmigos)
		resize();

	bool esta = false;
	for(int i = 0; i < numAmigos && !esta; i++)
		if(idAmigos[i] == idnuevoamigo)
			esta = true;

	if(!esta)
	{
		idAmigos[numAmigos] = idnuevoamigo;
		numAmigos++;
	}

	return !esta;
}

bool Usuario::eliminaAmigo(int idamigo){
  	bool status = false;

	for(int i = 0; i < numAmigos && !status; i++)
	{
		if(idAmigos[i] == idamigo)
		{
			idAmigos[i] = idAmigos[numAmigos-1];
			numAmigos--;
			status = true;
		}
	}
	return status;
}

void Usuario::incrementaNumPeliculas(){
   	numpeliculas++;
}


int & Usuario::operator[](int i) const{
	int num = -1;

     	if(i >= 0 && i < numAmigos)
		return idAmigos[i];
	else
		return num;
}

bool operator==( const Usuario & izq, const Usuario & dch){
	return izq.getNumPeliculas() == dch.getNumPeliculas();
}

bool operator!=( const Usuario & izq, const  Usuario & dch){
	return !(izq == dch);
}

bool operator<( const Usuario &izq, const Usuario & dch){
	return izq.getNumPeliculas() < dch.getNumPeliculas();
}

bool operator>( const Usuario &izq, const Usuario & dch){
	return izq.getNumPeliculas() > dch.getNumPeliculas();
}

bool operator<=( const Usuario &izq,  const Usuario & dch){
  	return !(izq > dch);
}

bool operator>=( const Usuario &izq, const Usuario & dch){
     return !(izq < dch);
}

std::ostream & operator << (std::ostream & flujo, const  Usuario & user){
       	flujo << user.id << " " << user.nombreusuario << " " << user.correoelectronico << " "
		<< user.numpeliculas << " " << user.numAmigos << ": ";

	for(int i = 0; i < user.getNumAmigos(); i++)
		flujo << user[i] << " ";

	return flujo;
}

string Usuario::to_string() const
{
	string result = std::to_string(id) + " " + nombreusuario + " " + correoelectronico + " " + std::to_string(numpeliculas);
        return result;
}

int Usuario::getNumAmigos() const
{
	return numAmigos;
}
