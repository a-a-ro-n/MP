#include "Par.h"
#include <iostream>

using namespace std;
/**
  @file Par.cpp
  @class Par
  Esta clase implementa el manejo para 2 valores de enteros, x e y.
*/

/**
@brief Constructor por defecto
@post Los valores miembro de la clase quedan inicializados a 0
*/
Par::Par()
{
    x=0;
    y=0;
}

        /**
@brief Constructor con valores
@pre newx y newy deben estar inicializados a un determinado valor
@param newx es el nuevo valor de x
@param newy es el nuevo valor para el dato miembro y
@post Los valores miembro de la clase quedan inicializados a los valores indicados
*/
Par::Par(int newx, int newy){
    x = newx;
    y = newy;
}
Par::~Par()
{
    //dtor
}

/**
@brief Devuelve el valor de x
@return Devuelve el valor x de la pareja
*/
int Par::verX(){
    return x;
}
/**
@brief Devuelve el valor de y
@return Devuelve el valor y de la pareja
*/
int Par::verY(){
    return y;
}

/**
@brief Modifica el dato miembro x asignándole un nuevo valor.
@param newx Indica el nuevo valor del entero x
*/
void Par::setX(int newx){
    x = newx;
}

/**
@brief Modifica el dato miembro y asignándole un nuevo valor.
@param newy Indica el nuevo valor del entero y
*/
void Par::setY(int newy){
    y = newy;
}

/**
@brief Muestra por pantalla los valores del Par. Utiliza el comando cout
*/
void Par::mostrar(){
    cout << x << " " << y << endl;
}

/**
@brief Suma los valores de dos pares. El x de un par de suma al x del segundo par y el y de un par se suma con el y del otro par. Se genera un nuevo Par que almacena el resultado.
@param uno es uno de los pares que se suman.
@param dos es uno dea los pares que se suman.
@return resultado es el par que contiene la suma de ambos pares que entran como parámetro.
@pre los pares deben estar inicializados correctamente.
@post se genera un par resultado con valores válidos.
*/
Par suma(Par uno, Par dos){
    Par resultado;
    resultado.setX(uno.verX()+ dos.verX());
    resultado.setY(uno.verY()+dos.verY());
    return resultado;
}
