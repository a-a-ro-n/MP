/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: jamor
 *
 * Created on 26 de septiembre de 2022, 11:03
 */

#include <cstdlib>
#include "Pelicula.h"
#include "ConjuntoPeliculas.h"
#include <iostream>
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    /*Pelicula peli(2,"hola",2022,4.5,"accion");
    //cout << peli.to_string();        
    Pelicula pelivacia;
    //cout << pelivacia.to_string();
    ConjuntoPeliculas pelis;
    pelis.leerFichero("./data/reducedactionmovies.csv",100);
  // pelis.leerFichero("./data/ficherocreado.csv",90);
   cout << pelis.to_string();
   cout << endl << endl;
    pelis.ordenaporranking();
    pelis.borrar(90);
    cout << pelis.to_string();
    pelis.escribeFichero("./data/ficherocreado.csv");
    cout << endl << endl;
    cout << pelis.at(64).to_string();
    return 0;*/


    // --- PRUEBAS DE LA CLASE PELICULA ---
    cout << "--- PRUEBAS CLASE PELICULA ---" << endl;

    // 1. Probar constructor por defecto
    Pelicula p1;
    cout << "P1 (vacia): " << p1.to_string();

    // 2. Probar constructor con parametros
    Pelicula p2(10, "Pulp Fiction", 1994, 8.9, "Crimen");
    cout << "P2 (con datos): " << p2.to_string();

    // 3. Probar los SETTERS por referencia (los que devuelven &)
    cout << "Modificando P1 usando referencias..." << endl;
    p1.setId() = 1;
    p1.setNombre() = "Titanic";
    p1.setAnio() = 1997;
    p1.setValoracion() = 7.8;
    p1.setGenero() = "Drama";
    cout << "P1 modificada: " << p1.to_string();

    // 4. Probar GETTERS
    cout << "Probando getters en P2: " << endl;
    cout << "ID: " << p2.getId() << ", Nombre: " << p2.getNombre() << ", Valoracion: " << p2.getValoracion() << endl;


    // --- PRUEBAS DE LA CLASE CONJUNTO PELICULAS ---
    cout << endl << "--- PRUEBAS CLASE CONJUNTO PELICULAS ---" << endl;
    
    ConjuntoPeliculas misPelis;

    // 1. Añadir peliculas
    cout << "Anadiendo peliculas..." << endl;
    misPelis.aniadePelicula(1, "Zombieland", 2009, 7.6, "Comedia");
    misPelis.aniadePelicula(2, "Avatar", 2009, 0.8, "Ciencia Ficcion");
    misPelis.aniadePelicula(3, "Batman", 2005, 3.2, "Accion");
    
    cout << "Lista actual:" << endl << misPelis.to_string();

    // 2. Probar busqueda (at)
    cout << "Buscando la pelicula con ID 2..." << endl;
    Pelicula encontrada = misPelis.at(2);
    cout << "Encontrada: " << encontrada.to_string();

    // 3. Probar ordenacion por ranking (Insercion)
    // El algoritmo de insercion va comparando y moviendo elementos.
    // 
    cout << "Ordenando por ranking (valoracion)..." << endl;
    misPelis.ordenaporranking();
    cout << "Lista ordenada:" << endl << misPelis.to_string();

    // 4. Probar borrar
    cout << "Borrando pelicula con ID 1 (Zombieland)..." << endl;
    misPelis.borrar(1);
    cout << "Lista tras borrar ID 1:" << endl << misPelis.to_string();

    // 5. Probar vaciado
    cout << "Limpiando todo el conjunto..." << endl;
    misPelis.clear();
    cout << "Lista final (debe estar vacia):" << endl << misPelis.to_string();

    cout << endl << "--- FIN DE LAS PRUEBAS ---" << endl;

    return 0;

}

