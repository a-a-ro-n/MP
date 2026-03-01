#include "Carta.hpp"

#include <iostream>
#include <string>

using namespace std;

/**
	@file carta.cpp
	@class Carta
	@brief Este archivo implementa los metodos y fuciones hayados
	en el archivo Carta.hpp
*/

/**
	@brief Constructor por defecto
	@post Se crea una instancia de tipo carta vacia
*/
Carta::Carta(){}


/**
	@brief Constructor con dos parametros
	@param nuevopalo parametro que especifica el tipo de palo de la carta
	@param nuevonum parametro que especifica el numero de la carta
	@post Se crea una instancia de tipo carta con los valores inicializados
	a los valores pasados como parametro
	@pre los parametros deben esstar correctamente inicalizados
*/
Carta::Carta(const tipopalo & nuevopalo, const int nuevonum)
{
	num = nuevonum;
	palo = nuevopalo;
}


/**
	@brief Constructor con un parametro
	@param orig Carta de la cual se obtendran los datos para formar una copiia de
	la misma
	@post Se crea una instancia de tipo carta con los valores inicializados
	a los valores de la carta pasada como parametro
	@pre el parametro debe esstar correctamente inicalizado
*/
Carta::Carta(const Carta & orig)
{
    num = orig.num;
    palo = orig.palo;

}


/**
	@brief Metodo para imprimir por pantalla el palo y el total de cartar
	@return palocarta devuelve el total de cartas que tienen un palo determinado
*/
string Carta::to_string() const
{
    string palocarta;
    palocarta = std::to_string(num) + " de " +  paloCartastring();
    return palocarta;
}


/**
	@brief "Setter" modifica una carta
	@param tipopalo especifica el palo al que se va a cambiar la carta
	@param nuevonum especifica el numero al que se va a cambiar la carta
	@pre los parametros deben esstar correctamente inicalizados
*/
void Carta::modificaCarta(const tipopalo & nuevopalo,const int nuevonum)
{
    palo = nuevopalo;
    num = nuevonum;
}


/**
	@brief "Getter" obtencion del numero de la carta
	@return num es el numero que se devuelve de la la carta
*/
int Carta::numero() const
{
    return num;
}


/**
	@brief "Getter" obtencon del palo de la carta
	@return palocarta es el palo de la carta
*/
string Carta::paloCartastring() const
{
    string palocarta;
    if(palo == bastos)  palocarta = "bastos";
    if(palo == espadas) palocarta = "espadas";
    if(palo == oros) palocarta = "oros";
    if(palo == copas) palocarta = "copas";
    return palocarta;
}


/**
	@brief "Getter" del tipo de palo de la carta
	@return palo devuelve el tipo de carta
*/
tipopalo Carta::paloCarta() const
{
    return palo;
}


/**
	@brief destructor por defecto
*/
Carta::~Carta(){}

