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

/**
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
    return 0;
}
*/

#include <iostream>
#include <string>
#include "Pelicula.h"
#include "ConjuntoPeliculas.h"

using namespace std;

int main() {
    // --- NUEVA SECCIÓN: LECTURA DE ARCHIVO ---
    ConjuntoPeliculas misPelis;
    string ruta;
    int cantidad;

    cout << "Introduce la ruta del archivo (.csv): ";
    cin >> ruta; 
    
    cout << "Cuantas peliculas quieres cargar como maximo? ";
    cin >> cantidad;

    cout << "Cargando datos desde: " << ruta << "..." << endl;
    
    // Llamamos a tu metodo de lectura
    misPelis.leerFichero(ruta, cantidad);

    cout << "Contenido cargado:" << endl;
    cout << misPelis.to_string() << endl;

    // --- PRUEBAS DE LA CLASE PELICULA ---
    cout << "--- PRUEBAS CLASE PELICULA ---" << endl;

    Pelicula p1;
    cout << "P1 (vacia): " << p1.to_string();

    Pelicula p2(10, "Pulp Fiction", 1994, 8.9, "Crimen");
    cout << "P2 (con datos): " << p2.to_string();

    // Probando los SETTERS por referencia (p1.setId() = 1)
    cout << "Modificando P1 usando referencias..." << endl;
    p1.setId() = 1;
    p1.setNombre() = "Titanic";
    p1.setAnio() = 1997;
    p1.setValoracion() = 7.8;
    p1.setGenero() = "Drama";
    cout << "P1 modificada: " << p1.to_string();

    // --- PRUEBAS EXTRAS SOBRE EL CONJUNTO CARGADO ---
    if (misPelis.to_string() != "") {
        cout << endl << "--- PRUEBAS CON DATOS DEL FICHERO ---" << endl;

        // Probar ordenación (Algoritmo de Inserción)
        cout << "Ordenando peliculas del fichero por ranking..." << endl;
        misPelis.ordenaporranking();
        cout << misPelis.to_string();

        // Probar borrar (intentamos borrar el ID 1 o el que sepas que existe)
        cout << "Borrando una pelicula (ID 1)..." << endl;
        misPelis.borrar(1);
        cout << "Lista tras borrar:" << endl << misPelis.to_string();
    }

    cout << endl << "--- FIN DE LAS PRUEBAS ---" << endl;

    return 0;
}
