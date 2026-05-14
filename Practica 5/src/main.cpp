#include "Opiniones.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

// Prototipo de la función de test exhaustivo
void ejecutarTestExhaustivo();

int main(int argc, char* argv[])
{
    // Si se ejecuta sin argumentos o con -a test_total, entra en modo verificación
    if (argc == 1 || (argc > 1 && string(argv[1]) == "test_total"))
    {
        ejecutarTestExhaustivo();
        return 0;
    }

    string accion = "";
    int idusuario = -1;
    int numusuarios = -1;
    string ficherousuarios = "";
    string ficheroopiniones = "";
    string ficheropeliculas = "";
    string nombrepelicula = "";
    float valoropinion = -999.0f;

    // Procesamiento de argumentos para el guion de prácticas
    for(int i = 1; i < argc; ++i)
    {
        string arg = argv[i];

        if (arg == "-a" && i + 1 < argc)
            accion = argv[++i];
        else if (arg == "-u" && i + 1 < argc)
            idusuario = stoi(argv[++i]);
        else if (arg == "-n" && i + 1 < argc)
            numusuarios = stoi(argv[++i]);
        else if (arg == "-fu" && i + 1 < argc)
            ficherousuarios = argv[++i];
        else if (arg == "-fo" && i + 1 < argc)
            ficheroopiniones = argv[++i];
        else if (arg == "-fp" && i + 1 < argc)
            ficheropeliculas = argv[++i];
        else if (arg == "-p" && i + 1 < argc)
        {
            nombrepelicula = argv[++i];
            for(size_t j = 0; j < nombrepelicula.length(); j++)
                if(nombrepelicula[j] == '_') nombrepelicula[j] = ' ';
        }
        else if (arg == "-op" && i + 1 < argc) valoropinion = stof(argv[++i]);
    }

    if(accion == "" || ficherousuarios == "" || ficheroopiniones == "" || ficheropeliculas == "")
    {
        cerr << "Error: Faltan argumentos básicos (-a, -fu, -fo, -fp)." << endl;
        return 1;
    }

    Opinion op(ficheroopiniones, ficheropeliculas, ficherousuarios);

    if(accion == "recomendacion")
    {
        if(idusuario != -1 && numusuarios != -1)
            generaRecomendacionUsuario(op, idusuario, numusuarios);
        else
            cerr << "Error: Faltan parámetros (-u, -n)." << endl;
    }
    else if (accion == "valoracionpelicula")
    {
        if(nombrepelicula != "")
            calculaConsensoPelicula(op, nombrepelicula);
        else
            cerr << "Error: Falta parámetro (-p)." << endl;
    }
    else if (accion == "modificacion")
    {
        if (idusuario != -1 && nombrepelicula != "" && valoropinion != -999.0f)
            cambiaOpinion(idusuario, nombrepelicula, valoropinion, op, ficheroopiniones, ficheropeliculas, ficherousuarios);
        else
            cerr << "Error: Faltan parámetros (-u, -p, -op)." << endl;
    }

    return 0;
}

void ejecutarTestExhaustivo()
{
    cout << "=== INICIANDO TEST DE CLASES ===" << endl;

    // 1. TEST CLASE USUARIO
    cout << "\n[1] Test Usuario..." << endl;

    // Los IDs DEBEN ir del 0 en adelante para que coincidan con la indexación de las matrices.
    Usuario u1(0, "Alice", "alice@test.com");
    u1.anaideAmigo(1); u1.anaideAmigo(2);

    Usuario u2(1, "Bob", "bob@test.com");
    u2.anaideAmigo(0); u2.anaideAmigo(3); u2.anaideAmigo(4);

    Usuario u3(2, "Charlie", "charlie@test.com");
    u3.anaideAmigo(0);

    Usuario u4(3, "Diana", "diana@test.com");
    u4.anaideAmigo(1); u4.anaideAmigo(4);

    Usuario u5(4, "Eve", "eve@test.com");
    u5.anaideAmigo(1); u5.anaideAmigo(3);

    cout << " - Usuarios: Creados 5 usuarios con listas de amigos OK." << endl;

    // 2. TEST CLASE PELICULA
    cout << "\n[2] Test Pelicula..." << endl;
    // IDs del 0 al 3 para cuadrar perfectamente en las 4 columnas de la matriz
    Pelicula p1(0, "Inception", 2010, 8.8, "Ciencia_Ficcion");
    Pelicula p2(1, "The Matrix", 1999, 8.7, "Ciencia_Ficcion");
    Pelicula p3(2, "Interstellar", 2014, 8.6, "Aventura");
    Pelicula p4(3, "Dune", 2021, 8.0, "Ciencia_Ficcion");

    cout << " - Peliculas: Creadas 4 peliculas de prueba OK." << endl;

    // 3. TEST CONJUNTO USUARIOS
    cout << "\n[3] Test ConjuntoUsuarios..." << endl;
    ConjuntoUsuarios conjU(2);
    conjU += u1;
    conjU += u2;
    conjU += u3;
    conjU += u4;
    conjU += u5;

    assert(conjU.getNumUsuarios() == 5);
    cout << " - ConjuntoUsuarios: Redimensionamiento dinámico y carga OK." << endl;

    // 4. TEST CONJUNTO PELICULAS
    cout << "\n[4] Test ConjuntoPeliculas..." << endl;
    ConjuntoPeliculas conjP;
    conjP += p1;
    conjP += p2;
    conjP += p3;
    conjP += p4;

    assert(conjP.getNumPeliculas() == 4);
    cout << " - ConjuntoPeliculas: Búsqueda y Adición OK." << endl;

    // 5. TEST SOBRECARGA OPERADORES >> Y <<
    cout << "\n[5] Test Operadores de Flujo (>> y <<)..." << endl;
    stringstream ss;
    ss << "99 NuevoUser nuevo@test.com 0 2 { 101 102 }";
    Usuario uStream;
    ss >> uStream;
    cout << " - Usuario leído desde stream: " << uStream.getNombreUsuario() << " (ID: " << uStream.getId() << ")" << endl;

    // 6. TEST CLASE OPINIONES (Matriz y Recomendación)
    cout << "\n[6] Test Clase Opiniones..." << endl;
    Opinion opTest(conjU, conjP);

    // Al alinear los IDs con la indexación [0-4] y [0-3], los valores se insertarán correctamente en la memoria.
    opTest.introduceOpinion(0, 0, 9.5); // Alice valora Inception
    opTest.introduceOpinion(0, 1, 8.0); // Alice valora The Matrix

    opTest.introduceOpinion(1, 1, 9.0); // Bob valora The Matrix
    opTest.introduceOpinion(1, 2, 7.5); // Bob valora Interstellar

    opTest.introduceOpinion(2, 0, 9.0); // Charlie valora Inception
    opTest.introduceOpinion(2, 3, 8.5); // Charlie valora Dune

    opTest.introduceOpinion(3, 2, 10.0); // Diana valora Interstellar
    opTest.introduceOpinion(3, 3, 9.5); // Diana valora Dune

    opTest.introduceOpinion(4, 0, 7.0); // Eve valora Inception
    opTest.introduceOpinion(4, 1, 6.0); // Eve valora The Matrix
    opTest.introduceOpinion(4, 3, 9.5); // Eve valora Dune

    int filas = opTest.getUsers().getNumUsuarios();
    int columnas = opTest.getPelis().getNumPeliculas();

    cout << " - Opiniones: Matriz dinámica cargada con valoraciones reales OK." << endl;

    // 7. SALIDA FINAL DE OPINIONES
    cout << "\n[7] Visualización del estado final del objeto Opiniones:" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << ">>> DIMENSIONES DE LA MATRIZ: " << filas << " Filas (Usuarios) x " << columnas << " Columnas (Peliculas) <<<" << endl;
    cout << opTest << endl;
    cout << "--------------------------------------------------------" << endl;

    cout << "\n=== TODOS LOS TESTS COMPLETADOS CON ÉXITO ===" << endl;
}
