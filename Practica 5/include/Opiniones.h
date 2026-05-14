#ifndef OPINIONES_H
#define OPINIONES_H

#include "ConjuntoUsuarios.h"
#include "ConjuntoPeliculas.h"

#include <string>

using namespace std;

class Opinion
{
private:
	float ** opiniones;
	int fil,col;
	ConjuntoUsuarios users;
	ConjuntoPeliculas pelis;

public:
	Opinion();
	Opinion(const int, const int);
	Opinion(const ConjuntoUsuarios &, const ConjuntoPeliculas &);
	Opinion(const string &, const string &, const string &);
	Opinion(const Opinion &);
	~Opinion();

	void saveData(string &,string &,string &);
	void cargaOpiniones(const string &);
	void introduceOpinion(const int,const int,const float);
	void eliminaOpinion(const int, const int);
	string to_string() const;

	void setFil(const int);
	void setCol(const int);

	const ConjuntoUsuarios & getUsers() const;
	const ConjuntoPeliculas & getPelis() const;

	ConjuntoPeliculas peliculasRecomendadas(const int, const int);

	float similitud(const int,const int);
	ConjuntoUsuarios usuariosSimilares(const int, const int);
	void ordenarPorSimilitud(ConjuntoUsuarios &, const int);

	float consensoPelicula(const int);
	float consenso();
	float medidaPelicula(const int);

	friend std::ostream & operator<<(std::ostream &, const Opinion &);
	friend std::istream & operator>>(std::istream &, Opinion &);
};

void generaRecomendacionUsuario(Opinion &op, int idusuario, int numusers);
void calculaConsensoPelicula(Opinion &op, string nombrepelicula);
void cambiaOpinion(int idusuario, string nombrepelicula, float valor, Opinion &op, string fichopiniones, string fichpeliculas, string fichusuarios);

#endif // OPINIONES_H
