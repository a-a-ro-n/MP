/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 24 de febrero de 2022, 7:37
 */

#include <cstdlib>
#include "Usuario.h"
#include "ConjuntoUsuarios.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Pruebas usuario
    Usuario user1(1,"Nick1","user1@correo.es");
    Usuario user2(2,"Nick2","user2@correo.es");
    Usuario user3(3,"Nick3","user3@correo.es");
    Usuario user4(7,"Nick4", "user4@correo.es");
    Usuario user5(6,"Nick5", "user5@correo.es");
    Usuario user6(5,"Nick6", "user6@correo.es");
    Usuario user7(4,"Nick7", "user7@correo.es");
    user1.incrementaNumPeliculas();
    user1.incrementaNumPeliculas();
    user1.incrementaNumPeliculas();
    user1.incrementaNumPeliculas();
    
    user2.incrementaNumPeliculas();
    user2.incrementaNumPeliculas();
    
    user3.incrementaNumPeliculas();
    cout << user1 << endl << user2 << endl << user3 << endl;
    if(user1 > user2) cout << "Ok-1" << endl;
    if (!(user1 < user2)) cout << "Ok-2" << endl;
    if(user1 == user1) cout << "Ok-3" << endl;
    if(user1 >= user2) cout << "Ok-4" << endl;
    if(user3 <= user2) cout << "Ok-5" << endl;
    
    user1.anaideAmigo(6);
    if(!(user1.anaideAmigo(6))) cout << "Ok-6" << endl;
    user1.anaideAmigo(4);
    user1.anaideAmigo(2);
    user1.anaideAmigo(3);
    user1.anaideAmigo(7);
    user1.anaideAmigo(10);
    user1.anaideAmigo(15);
    user1.eliminaAmigo(4);
    
    user2.anaideAmigo(3);
    user2.anaideAmigo(6);
    user2.anaideAmigo(5);
    user2.anaideAmigo(9);
    user3.anaideAmigo(6);
    
    cout << user1 << endl;
    cout << user1[2] << endl;
   
    cout << endl << endl << "PRUEBAS CONJUNTO USUARIOS" << endl;
    //Pruebas conjuntoUsuarios
    ConjuntoUsuarios conj;
    ConjuntoUsuarios conj2;
    ConjuntoUsuarios conj4;
    conj += user1;
    conj+=user2;
    conj+=user3;
    conj2+=user4;
    conj4+=user5;
    conj4+=user6;
    Usuario pruebaasignacion = conj[1];
    cout << conj[0];
  
    
   ConjuntoUsuarios conj3 = conj+conj2+conj4;
   cout << endl;
   conj3+=user7;
   cout << endl << "Prueba operador+" << endl;
   cout << conj3 << endl;
     cout << "Busquedas:" << endl;
    
     cout << conj3.buscaUsuario(2) << endl;
  
    cout << conj3.buscaUsuario("Nick5") << endl;
    
    conj3.optimizar();
    
    cout << conj3 << endl;
    conj3.eliminaUsuario(2);
    cout << conj3 << endl;
    cout << conj.rankingUsuarios() << endl;
    return 0;
}

