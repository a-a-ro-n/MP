#ifndef __MANO_HPP__
#define __MANO_HPP__

#include <iostream>
#include "TipoPalo.hpp"
#include "Carta.hpp"

/**
	@file Mano.hpp
	@class Mano
	@brief En esta clase se muestra como el usuario obtendra las cartas
	se pueden realizar consultas y modificaciones a las cartas
*/
class Mano
{
    	private:
		/**
			@brief Tamaño maximo del array de cartas
		*/
		static const int MAX = 10;

		/**
			@brief Array de cartas que forma la mano del jugador
		*/
	    	Carta cartas[MAX];

		/**
			@brief total de cartas enn la mano del jugador
		*/
	    	int numCartas=0;
	public:
  		 Mano();

		Mano(const Mano &);
		~Mano();
		void anaideCarta(Carta &);
		void descartaCarta(const int);
		void cambiaCarta(const Carta &,const int);
    		std::string to_string() const;
		int  numeroCartas() const;
    		const Carta & carta(const int) const;
};

int cartasComunes(const Mano &, const Mano &);

#endif __MANO_HPP__
