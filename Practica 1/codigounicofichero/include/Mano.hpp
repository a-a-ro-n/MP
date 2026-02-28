#ifndef __MANO_HPP__
#define __MANO_HPP__

#include <iostream>
#include "TipoPalo.hpp"
#include "Carta.hpp"

class Mano
{
    	private:
		static const int MAX = 10;
	    	Carta cartas[MAX];
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
