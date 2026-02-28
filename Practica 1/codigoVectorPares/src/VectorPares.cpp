#include "VectorPares.h"

#include <iostream>

using namespace std;

/**
@brief Constructor de la clase. No hay que hacer nada porque hemos inicializado los valores en el .h
*/

VectorPares::VectorPares()
{
    //ctor
}

/**
@brief Accedemos en modo lectura a uno de los pares del vector.
@param i posición del vector de la que queremos obtener el par.
@pre i debe ser un valor menor que tam.
@post El vector de pares no se modifica.
@return Devuelve el objeto Par que hay en la posición i del vector.
*/
Par VectorPares::at(int i){
    if (i < MAX && i < tam){
        return pares[i];
    }else{
        return Par();
    }
}

/**
@brief Modificamos una posición del vector ya existente.
@param i posición del vector de la que queremos modificar.
@pre i debe ser un valor menor que tam.
@post El vector de pares queda modificado con el nuevo valor introducido.
*/
void VectorPares::modifica(int i, Par newpar){
    if(i < MAX && i < tam){
        pares[i] = newpar;
    }
}

/**
@brief Imprimimos todo el vector de pares por pantalla. Utilizamos la función de imprimir por pantalla de Par.
*/
void VectorPares::imprime(){
    for(int i = 0; i < tam; i++){
        pares[i].mostrar();
    }
}

/**
@brief Añade un nuevo par al final del vector.
@param newpar Es el objeto par que añadimos al vector.
@pre Debe haber espacio reservado en el vector. Es decir, tam debe de ser menor que MAX-
@post el vector añade un nuevo par al final
*/
void VectorPares::anaide(Par newpar){
    if(tam < MAX){
        pares[tam]= newpar;
        tam++;
    }
}

/**
@brief Devuelve el tamaño actual del vector
@return Devuelve un entero que contiene el tamaño total del vector.
*/
int VectorPares::tamanioactual(){
    return tam;
}

