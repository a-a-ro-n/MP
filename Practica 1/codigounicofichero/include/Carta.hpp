
#ifndef __CARTA_HPP__
#define __CARTA_HPP__

#include <iostream>
#include "TipoPalo.hpp"

/**
	@file Carta.hpp
	@class Carta
	@brief Esta clase permite instanciar objetos de tipo carta
	donde se refleja el umero y el palo de la misma.
	En esta clase se permiten conultas y modificaciones a datos privados
	a demas de una nnnicializaciion distinta dependiendo de las necesidades
	del usuario
*/
class Carta
{
	private:
		/**
			@brief Palo de la carta
		*/
		tipopalo palo;

		/**
			@brief Numero de la carta
		*/
		int num;

	public:
		Carta();
		Carta(const tipopalo &, const int);
		Carta(const Carta &);
		~Carta();
		std::string to_string() const ;
		void modificaCarta(const tipopalo &, const int);
		int numero() const;
		std::string paloCartastring() const;
		tipopalo paloCarta() const;
};

#endif __CARTA_HPP__
