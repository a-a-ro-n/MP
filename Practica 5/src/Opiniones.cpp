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
	col = newpelis.getNumPeliculas();

	opiniones = new float*[fil];
	for(int i = 0; i < fil; i++)
		opiniones[i] = new float[col];

	for(int i = 0; i < fil; i++)
		for(int j = 0; j < col; j++)
			opiniones[i][j] = -1;
}

Opinion::Opinion(const string & fichopiniones, const string & fichpelis, const std::string & fichusuarios)
{
    ConjuntoUsuarios conjuser(fichusuarios);
    ConjuntoPeliculas conjpeli(fichpelis);

    users = conjuser;
    pelis = conjpeli;

    fil = users.getNumUsuarios();
    col = pelis.getNumPeliculas();

    opiniones = new float*[fil];
    for(int i = 0; i < fil; i++)
    {
        opiniones[i] = new float[col];
        for(int j = 0; j < col; j++)
            opiniones[i][j] = -1;
    }

    cargaOpiniones(fichopiniones);
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
		for(int j = 0; j < col; j++)
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
    ofstream outOp(fichopiniones);
    if(outOp.is_open()) {
        outOp << fil << " " << col << endl;
        for(int i = 0; i < fil; i++) {
            for(int j = 0; j < col; j++) {
                outOp << opiniones[i][j];
                if(j < col - 1) outOp << " ";
            }
            outOp << endl;
        }
        outOp.close();
    }

    pelis.escribeFichero(fichpelis);

    ofstream outUs(fichusuario);
    if(outUs.is_open()) {
        outUs << users.getNumUsuarios() << endl;
        outUs << users;
        outUs.close();
    }
}

void Opinion::cargaOpiniones(const string & fichopiniones)
{
	ifstream arch(fichopiniones);
	if(arch.is_open())
	{
		arch >> *this;
		arch.close();
	}
}

void Opinion::introduceOpinion(const int iduser ,const int idpelicula,const float valor)
{
	if((iduser >= 0 && iduser < fil) && (idpelicula >= 0 && idpelicula < col))
	{
		if(opiniones[iduser][idpelicula] == -1)
			users[iduser].incrementaNumPeliculas();

		opiniones[iduser][idpelicula] = valor;
	}
}

void Opinion::eliminaOpinion(const int iduser, const int idpeli)
{
	if((iduser >= 0 && iduser < fil) && (idpeli >= 0 && idpeli < col))
	{
		if(opiniones[iduser][idpeli] != -1)
		{
			users[iduser].decrementaNumPeliculas();
			opiniones[iduser][idpeli] = -1;
		}
	}
}

string Opinion::to_string() const
{
	string result = "";

    	int n_usuarios = users.getNumUsuarios();
    	int n_peliculas = pelis.getNumPeliculas();

    	for (int i = 0; i < n_usuarios; i++) {
        	for (int j = 0; j < n_peliculas; j++)
            		result += std::to_string(opiniones[i][j]) + " ";

        	result += "\n";
    	}

    	return result;
}

const ConjuntoUsuarios & Opinion::getUsers() const
{
	return users;
}

const ConjuntoPeliculas & Opinion::getPelis() const
{
	return pelis;
}

ConjuntoPeliculas Opinion::peliculasRecomendadas(const int userid, const int numusers)
{
    ConjuntoUsuarios usuarios = usuariosSimilares(userid,numusers);
    ConjuntoPeliculas peliculas;

    int idx_userid = users.buscaUsuario(userid);
    if (idx_userid < 0 || idx_userid >= fil) return peliculas;

    for(int i = 0; i < usuarios.getNumUsuarios(); i++)
    {
        int idx_similar = users.buscaUsuario(usuarios[i].getId());

        if (idx_similar < 0 || idx_similar >= fil)
            continue;

        for(int j = 0; j < pelis.getNumPeliculas(); j++)
        {
            if(j >= col)
                break;

            if(opiniones[idx_similar][j] > 6.0 && opiniones[idx_userid][j] == -1.0)
                if(peliculas.buscar(pelis[j].getId()) == -1)
                    peliculas += pelis[j];
        }
    }

    peliculas.ordenaporranking();
    return peliculas;
}

float Opinion::similitud(const int userid1, const int userid2)
{
    if(userid1 < 0 || userid1 >= fil || userid2 < 0 || userid2 >= fil)
        return -1;

    float suma_distancias = 0.0;
    int peliculas_en_comun = 0;
    int n_peliculas = pelis.getNumPeliculas();

    for(int j = 0; j < n_peliculas; j++)
	{
        if(opiniones[userid1][j] != -1 && opiniones[userid2][j] != -1)
		{
            float diff = opiniones[userid1][j] - opiniones[userid2][j];
            if(diff < 0)
                diff = -diff;

            suma_distancias += (diff / 10.0);
            peliculas_en_comun++;
        }
    }

    	if(peliculas_en_comun == 0)
        	return -1.0;

    	return suma_distancias / peliculas_en_comun;
}

void Opinion::ordenarPorSimilitud(ConjuntoUsuarios & conj, const int userid)
{
    int n = conj.getNumUsuarios();
    int idx_userid = users.buscaUsuario(userid);

    if (idx_userid == -1)
        return;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1 ; j++)
        {
            int idx_j = users.buscaUsuario(conj[j].getId());
            int idx_next = users.buscaUsuario(conj[j+1].getId());

            if (idx_j != -1 && idx_next != -1)
            {
                float sim_j = similitud(idx_j, idx_userid);
                float sim_i = similitud(idx_next, idx_userid);

                if(sim_j > sim_i)
                {
                    Usuario aux = conj[j];
                    conj[j] = conj[j+1];
                    conj[j+1] = aux;
                }
            }
        }
    }
}

ConjuntoUsuarios Opinion::usuariosSimilares(const int userid, const int numusers)
{
    ConjuntoUsuarios similares;
    int idx_userid = users.buscaUsuario(userid);

    if (idx_userid == -1)
        return similares;

    for(int i = 0; i < users.getNumUsuarios();i++)
    {
        if(users[i].getId() != userid)
        {
            float valor = similitud(i, idx_userid);
            if(valor >= 0.0)
                similares += users[i];
        }
    }

    if(similares.getNumUsuarios() == 0)
        return similares;

    ordenarPorSimilitud(similares,userid);

    ConjuntoUsuarios resultado;
    int limite = (similares.getNumUsuarios() < numusers) ? similares.getNumUsuarios() : numusers;
    for (int i = 0; i < limite; i++)
        resultado += similares[i];

    return resultado;
}
float Opinion::consensoPelicula(const int idpelicula)
{
    	float suma_distancias = 0.0;
    	int contador_parejas = 0;
    	int n_usuarios = users.getNumUsuarios();

    	for (int i = 0; i < n_usuarios; i++)
	{
       		if (opiniones[i][idpelicula] != -1)
		{

            		for (int j = i + 1; j < n_usuarios; j++)
			{
                		if (opiniones[j][idpelicula] != -1)
				{
                    			float diff = opiniones[i][idpelicula] - opiniones[j][idpelicula];
                    			if(diff < 0)
						diff = -diff;

                    			suma_distancias += (diff / 10.0);
                    			contador_parejas++;
                		}
            		}
        	}
    	}

    if (contador_parejas == 0)
        return 0.0;

    return suma_distancias / contador_parejas;
}

float Opinion::consenso()
{
    	float total_consenso = 0.0f;
    	int n_pelis = pelis.getNumPeliculas();

    	if(n_pelis == 0)
        	return 0.0;

    	for(int j = 0; j < n_pelis; j++)
        	total_consenso += consensoPelicula(j);

    	return total_consenso / n_pelis;
}

float Opinion::medidaPelicula(const int idpelicula)
{
    	float suma_puntuaciones = 0.0;
    	int contador_opiniones = 0, n_usuarios = users.getNumUsuarios();

    	for(int i = 0; i < n_usuarios; i++)
	{
        	if(opiniones[i][idpelicula] != -1)
		{
            		suma_puntuaciones += opiniones[i][idpelicula];
            		contador_opiniones++;
        	}
    	}

    	if(contador_opiniones == 0)
        	return -1.0;

    	return suma_puntuaciones / contador_opiniones;
}

void Opinion::setFil(const int FIL)
{
	fil = FIL;
}

void Opinion::setCol(const int COL)
{
	col = COL;
}

ostream & operator<<(std::ostream & flujo, const Opinion & op)
{
	flujo << "\nPELICULAS\n";
	flujo << op.getPelis().to_string();
	flujo << "\nUSUARIOS\n";
	flujo << op.getUsers();
	flujo << "\nOPINIONES\n";
	flujo << op.to_string();

	return flujo;
}

istream & operator>>(std::istream & flujo, Opinion & op)
{
	int FIL,COL;
    FIL = COL = 0;
	flujo >> FIL >> COL;
	if(FIL > 0 && COL > 0)
	{
        if(op.opiniones != nullptr)
        {
            for(int i = 0; i < op.fil;i++)
                delete[] op.opiniones[i];

            delete[] op.opiniones;
        }

		op.setFil(FIL);
		op.setCol(COL);

        op.opiniones = new float*[FIL];
        for(int i = 0; i < op.fil; i++)
        {
            op.opiniones[i] = new float[COL];
			for(int j = 0; j < COL; j++)
				flujo >> op.opiniones[i][j];
        }
    }
	else
		op = Opinion();

	return flujo;
}


void generaRecomendacionUsuario(Opinion & op, int idusuario, int numusers)
{
    	ConjuntoPeliculas recomendadas = op.peliculasRecomendadas(idusuario, numusers);

    	cout << "Recomendamos al usuario Nick" << idusuario + 1 << " las siguientes peliculas:" << endl;
    	cout << recomendadas.to_string();
}

void calculaConsensoPelicula(Opinion &op, string nombrepelicula) {
    	int idpelicula = op.getPelis().busquedaPelicula(nombrepelicula);

    	if(idpelicula == -1)
	{
        	cout << "Error: Pelicula no encontrada." << endl;
        	return;
    	}

    	cout << "Valoración de: " << nombrepelicula << endl;
    	cout << "Los usuarios dan una valoración media de " << op.medidaPelicula(idpelicula) << endl;
    	cout << "Esa valoración tiene un consenso de: " << op.consensoPelicula(idpelicula) << endl;
    	cout << "El consenso global de los usuarios en la plataforma es de:" << op.consenso() << endl;
}

void cambiaOpinion(int idusuario, string nombrepelicula, float valor, Opinion &op, string fichopiniones, string fichpeliculas, string fichusuarios) {
    	int idpelicula = op.getPelis().busquedaPelicula(nombrepelicula);

    	if(idpelicula == -1)
	{
        	cout << "Error: Pelicula no encontrada." << endl;
        	return;
    	}

    	if(valor == -1.0f)
        	op.eliminaOpinion(idusuario, idpelicula);
	else
       		op.introduceOpinion(idusuario, idpelicula, valor);

    	op.saveData(fichopiniones, fichpeliculas, fichusuarios);
}
