#include "Carta.hpp"

#include <iostream>
#include <string>
using namespace std;

Carta::Carta(){}

Carta::Carta(const tipopalo & nuevopalo, const int nuevonum)
{
	num = nuevonum;
	palo = nuevopalo;
}

Carta::Carta(const Carta & orig)
{
    num = orig.num;
    palo = orig.palo;

}

string Carta::to_string() const
{
    string palocarta;
    palocarta = std::to_string(num) + " de " +  paloCartastring();
    return palocarta;
}

void Carta::modificaCarta(const tipopalo & nuevopalo,const int nuevonum)
{
    palo = nuevopalo;
    num = nuevonum;
}

int Carta::numero() const
{
    return num;
}

string Carta::paloCartastring() const
{
    string palocarta;
    if(palo == bastos)  palocarta = "bastos";
    if(palo == espadas) palocarta = "espadas";
    if(palo == oros) palocarta = "oros";
    if(palo == copas) palocarta = "copas";
    return palocarta;
}

tipopalo Carta::paloCarta() const
{
    return palo;
}

Carta::~Carta(){}

