/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   conjuntoUsuarios.cpp
 * Author: Usuario
 * 
 * Created on 8 de febrero de 2022, 12:07
 */

#include "ConjuntoUsuarios.h"
#include <iostream>

using namespace std;

/*
private:
    void ordenaporId();
    void resize(int newtam);

    Usuario * vectorUsuarios;
    int numusuarios;
    int tamreservado;
    static const int INCREMENTO=5;
*/

ConjuntoUsuarios::ConjuntoUsuarios(int k) {
	tamreservado = k;
	vectorUsuarios = new Usuario[k];
	numusuarios = 0;
}

ConjuntoUsuarios & ConjuntoUsuarios::operator=(const ConjuntoUsuarios & orig){
	if(this != &orig)
	{
		if(vectorUsuarios)
			delete[] vectorUsuarios;

		tamreservado = orig.tamreservado;
		vectorUsuarios = new Usuario[tamreservado];

		for(int i = 0; i < orig.numusuarios; i++)
			vectorUsuarios[i] = orig.vectorUsuarios[i];

		numusuarios = orig.numusuarios;
	}

	return *this;
}

ConjuntoUsuarios::ConjuntoUsuarios(const ConjuntoUsuarios& orig) {
        tamreservado = orig.tamreservado;
	vectorUsuarios = new Usuario[tamreservado];

	for(int i = 0; i < orig.numusuarios; i++)
		vectorUsuarios[i] = orig.vectorUsuarios[i];

        numusuarios = orig.numusuarios;
}

ConjuntoUsuarios::~ConjuntoUsuarios() {
	if(vectorUsuarios)
		delete[] vectorUsuarios;

	tamreservado = numusuarios = 0;
	vectorUsuarios = nullptr;
}

ConjuntoUsuarios::ConjuntoUsuarios(int n, string *nombresusuario, string * correoselectronicos){
   	numusuarios = n;
	vectorUsuarios = new Usuario[numusuarios];

	for(int i = 0; i < numusuarios;i++)
	{
		vectorUsuarios[i].putNombreUsuario() = nombresusuario[i];
		vectorUsuarios[i].putCorreoElectronico() = correoselectronicos[i];
		vectorUsuarios[i].setId() = i+1;
	}
}

string ConjuntoUsuarios::rankingUsuarios(){
 	string ranking = "";
  	for(int i = 1; i < numusuarios;i++)
      	{
		Usuario aux = vectorUsuarios[i];
      		int j = i - 1;
      		while(j >= 0 && vectorUsuarios[j].getNumPeliculas() < aux.getNumPeliculas())
          	{
			vectorUsuarios[j + 1] = vectorUsuarios[j];
          		j--;
      			vectorUsuarios[j + 1] = aux;
		}
	}

	for(int i = 0; i < numusuarios; i++)
		ranking += vectorUsuarios[i].to_string() + "\n";

	return ranking;
}

std::ostream & operator<< (std::ostream & flujo, const ConjuntoUsuarios & conjuser){
	for(int i = 0; i < conjuser.getNumUsuarios(); i++)
		flujo << conjuser[i] << "\n";

	return flujo;
}

ConjuntoUsuarios & ConjuntoUsuarios::operator+=(const Usuario& newuser){
	if(numusuarios == tamreservado)
		resize(tamreservado+INCREMENTO);

	vectorUsuarios[numusuarios] = newuser;
	numusuarios++;

	return *this;
}

void ConjuntoUsuarios::eliminaUsuario(int userid){
	bool find = false;
	for(int i = 0; i < numusuarios && !find; i++)
	{
		if(userid == vectorUsuarios[i].getId())
		{
			vectorUsuarios[i] = vectorUsuarios[numusuarios-1];
			numusuarios--;
			find = true;
		}
	}
}

int ConjuntoUsuarios::buscaUsuario(int userid){
	bool find = false;
	int pos = -1;

	for(int i = 0; i < numusuarios && !find; i++)
	{
		if(userid == vectorUsuarios[i].getId())
		{
			find = true;
			pos = i;
		}
	}

	return pos;
}

int ConjuntoUsuarios::buscaUsuario(string nombreusuario){
        bool find = false;
        int pos = -1;

        for(int i = 0; i < numusuarios && !find; i++)
        {
                if(nombreusuario == vectorUsuarios[i].getNombreUsuario())
                {
                        find = true;
                        pos = i;
                }
        }

        return pos;
}

void ConjuntoUsuarios::optimizar(){

}

Usuario & ConjuntoUsuarios::operator[](int i) const{
	if(i >= 0 && i < numusuarios)
		return vectorUsuarios[i];
}

void ConjuntoUsuarios::ordenaporId(){
        for(int i = 1; i < numusuarios;i++)
        {
                Usuario aux = vectorUsuarios[i];
                int j = i - 1;
                while(j >= 0 && vectorUsuarios[j].getId() > aux.getId())
                {
                        vectorUsuarios[j + 1] = vectorUsuarios[j];
                        j--;
                        vectorUsuarios[j + 1] = aux;
                }
        }

}

void ConjuntoUsuarios::resize(int newtam){
       	if(newtam > 0)
	{
		if(tamreservado == 0)
		{
			tamreservado += newtam;
			numusuarios = 0;
			vectorUsuarios = new Usuario[tamreservado];
		}
		else
		{
			tamreservado += newtam;
			Usuario * aux = new Usuario[numusuarios];
			for(int i = 0; i < numusuarios; i++)
				aux[i] = vectorUsuarios[i];

			if(vectorUsuarios)
				delete[] vectorUsuarios;
			vectorUsuarios = new Usuario[tamreservado];
			for(int i = 0; i < numusuarios; i++)
				vectorUsuarios[i] = aux[i];

			if(aux)
				delete[] aux;
		}
	}
}

int ConjuntoUsuarios::getNumUsuarios() const
{
	return numusuarios;
}

ConjuntoUsuarios operator+( const ConjuntoUsuarios & left, const ConjuntoUsuarios & right){
	ConjuntoUsuarios result;

	for(int i = 0; i < left.getNumUsuarios(); i++)
		result += left[i];
	for(int j = 0; j < right.getNumUsuarios();j++)
		result += right[j];

	return result;
}
