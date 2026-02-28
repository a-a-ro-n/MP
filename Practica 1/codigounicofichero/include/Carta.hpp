#ifndef __CARTA_HPP__
#define __CARTA_HPP__

#include <iostream>
#include "TipoPalo.hpp"

class Carta
{
	private:
		tipopalo palo;
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
