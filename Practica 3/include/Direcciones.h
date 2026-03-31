#include <iostream>

using namespace std;

#ifndef __DIRECCIONES_H__
#define __DIRECCIONES_H__

enum Direccion
{
	Arriba,
	Abajo,
	Derecha,
	Izquierda,
	DiagonalArribaDer,
	DiagonalAbajoDer,
	DiagonalArribaIzq,
	DiagonalAbajoIzq,
	NOP
};

#endif // __DIRECCIONES_H__
