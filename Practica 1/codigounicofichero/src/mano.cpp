#include "Mano.hpp"

#include <iostream>
#include <string>

using namespace std;

/**
	@file mano.cpp
	@class Mano
	@brief Este archivo implementa los métodos y funciones hallados
	en el archivo Mano.hpp
*/

/**
	@brief Constructor por defecto
	@post Se crea un objeto de tipo Mano vacío
*/
Mano::Mano(){}

/**
	@brief Constructor de copia
	@param orig Mano de la cual se obtendrán los datos para formar una copia de la misma
	@post Se crea una instancia de tipo Mano con los valores inicializados a los de la mano pasada por parámetro
	@pre El parámetro debe estar correctamente inicializado
*/
Mano::Mano(const Mano& orig){}

/**
	@brief Destructor por defecto
*/
Mano::~Mano(){}

/**
	@brief Añade una carta a la mano
	@param nuevacarta Referencia a la carta que se va a añadir
	@post Se incrementa el número de cartas y se guarda la nueva carta en el array
	@pre Debe haber espacio en el array de cartas
*/
void Mano::anaideCarta(Carta & nuevacarta)
{
     cartas[numCartas] = nuevacarta;
     numCartas++;
}

/**
	@brief Elimina una carta de la mano
	@param pos Posición de la carta que se desea descartar
	@post Se elimina la carta y se reordenan las posiciones posteriores
	@pre La posición debe ser válida dentro del rango de cartas actuales
*/
void Mano::descartaCarta(const int pos)
{
        for(int i = pos; i < numCartas;i++){
            cartas[i] = cartas[i+1];
        }
         numCartas--;
}

/**
	@brief Modifica una carta específica de la mano
	@param nuevacarta Nueva carta que sustituirá a la anterior
	@param pos Posición de la carta que se va a cambiar
	@pre La posición debe estar correctamente inicializada
*/
void Mano::cambiaCarta(const Carta & nuevacarta,const int pos)
{
        cartas[pos] = nuevacarta;
}

/**
	@brief Genera una cadena de texto con la información de todas las cartas de la mano
	@return cadcartas String que contiene el listado de cartas
*/
string Mano::to_string() const
{
        string cadcartas="";
        for(int i = 0; i < numCartas;i++){
            cadcartas = cadcartas + std::to_string(cartas[i].numero())+ " de "+
                    cartas[i].paloCartastring() + "\n";
        }
        return cadcartas;
}

/**
	@brief "Getter" para obtener la cantidad de cartas en la mano
	@return numCartas Total de cartas actuales
*/
int  Mano::numeroCartas() const
{
        return numCartas;
}

/**
	@brief "Getter" para obtener una carta específica
	@param i Índice de la carta en el array
	@return cartas[i] Referencia constante a la carta solicitada
*/
const Carta & Mano::carta(int i) const
{
        return cartas[i];
}

/**
	@brief Función para calcular cuántas cartas coinciden entre dos manos
	@param mano1 Primera mano a comparar
	@param mano2 Segunda mano a comparar
	@return numrepetidas Total de cartas que tienen el mismo número y palo en ambas manos
*/
int cartasComunes(const Mano & mano1,const Mano & mano2)
{
        int numrepetidas=0;
        for(int i = 0; i < mano1.numeroCartas();i++){
            for(int j = 0; j < mano2.numeroCartas();j++){
                if(mano1.carta(i).numero() == mano2.carta(j).numero() &&
                        mano1.carta(i).paloCarta() == mano2.carta(j).paloCarta()){
                    numrepetidas++;
                }
            }
        }
        return numrepetidas;
}
