#include "Opiniones.h"
#include <iostream>

using namespace std;
/*
private:
        float ** opiniones;
        int fil,col;
        ConjuntoUsuarios users;
        ConjuntoPeliculas pelis;
*/

Opinion::Opinion()
{
	users = ConjuntoUsuarios();
	pelis = ConjuntoPeliculas();
	fil = col = 0;
	opiniones = nullptr;
}


Opinion::Opinion(const ConjuntoUsuarios & newusers,const ConjuntoPeliculas & newpelis)
{
	users = newusers;
	pelis = newpelis;

	fil = newusers.getNumUsuarios();
	col = newpelis.getNumPelis();

	opiniones = new float*[fil];
	for(int i = 0; i < fil; i++)
		opiniones[i] = float[col];

	for(int i = 0; i < fil; i++)
		for(int j = 0; j < col; j++)
			opiniones[i][j] = -1;
}

Opinion::Opinion(const string & fichopiniones, const string & fichpelis, const string & fichusuarios)
{
	ConjuntoUsuarios conjuser = ConjuntoUsuarios(fichusuarios);
	ConjuntoPeliculas conjpeli = ConjuntoPeliculas(fichpelis);

	Opinion(conjuser,conspeli);
}

Opinion::Opinion(const Opinion & op)
{
	users = op.users;
	pelis = op.pelis;

	fil = op.fil;
	col = op.col;

	opiniones = new float*[fil];
	for(int i = 0; i < fil; i++)
		opiniones[i] = new float[col];

	for(int i = 0; i < fil; i++)
		for(int i = 0; i < col; i++)
			opiniones[i][j] = op.opiniones[i][j];
}
Opinion::~Opinion()
{
	for(int i = 0; i < fil; i++)
		if(opiniones[i])
			delete[] opiniones[i];

	if(opiniones)
		delete[] opiniones;

	opiniones = nullptr;
	fil = col = 0;
}
void Opinion::saveData(string & fichopiniones, string & fichpelis, string & fichusuario)
{
	fichopiniones << *this;
	
}

void Opinion::cargaOpiniones(const string & fichopiniones)
{
	fichopiniones >> *this;
}

void Opinion::introduceOpinion(const int iduser ,const int idpelicula,const float valor)
{
	if((iduser >= 0 && iduser < fil) && (idpelicula >= 0 && idpelicula < col))
	{
		if(opiniones[iduser][idpelicula] == -1)
			users[idusers].incrementaNumPeliculas();

		opiniones[iduser][idpelicula] = valor;
	}
}

void Opinion::eliminaOpinion(const int iduser, const int ispeli)
{
	if((iduser >= 0 && iduser < fil) && (idpeli >= 0 && idpeli < col))
	{
		if(opiniones[iduser][idpeli] != -1)
		{
			users[idusers].decrementaNumPeliculas();
			opiniones[iduser][idpeli] = -1;
		}
	}
}

string Opinion::to_string() const
{
	string result = "";

    	int n_usuarios = users.numusuarios();
    	int n_peliculas = pelis.numpeliculas();

    	for (int i = 0; i < n_usuarios; i++) {
        	for (int j = 0; j < n_peliculas; j++)
            		result += std::to_string(opiniones[i][j]) + " ";

        	result += "\n";
    	}

    	return result;
}

ConjuntoUsuario & Opinion::getUsers() const
{
	return users;
}

ConjuntoPeliculas & Opinion::getPelis() const
{
	return pelis;
}

ConjuntoPeliculas Opinion::peliculasRecomendadas(const int userid, const int numusers)
{
	ConjuntoUsuarios usuarios = usuariosSimilares(userid,numusers);
	ConjuntoPeliculas pelis;

	for(int i = 0; i < usuarios.numusuarios(); i++)
	{
		;
	}
}

float Opinion::similitud(const int,const int);
ConjuntoUsuarios Opinion::usuariosSimilares(const int, const int);

float Opinion::consensoPelicula(const int);
float Opinion::medidaPelicula(const int);

ostream & Opinion::operator<<(std::ostream & flujo, const Opinion & op)
{
	flujo << "\nPELICULAS\n";
	flujo << pelis;
	flujo << "\nUSUARIOS\n";
	flujo << users;
	flujo << "\nOPINIONES\n";
	flujo << to_string();

	return flujo;
}

istream & Opinion::operator<<(std::istream & flujo, Opinion & op)
{
	string cabezeras;
	flujo >> cabezeras;
	if(cabeceras == "PELICULAS")
		flujo >> pelis;
	flujo << "\nUSUARIOS\n";
	flujo << users;
	flujo << "\nOPINIONES\n";
	flujo << to_string();

	return flujo;
}
