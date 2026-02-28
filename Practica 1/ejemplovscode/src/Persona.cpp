#include "Persona.h"

Persona::Persona(string nuevo)
{
    nombre = nuevo;
}

Persona::~Persona()
{

}

string Persona::verNombre(){
    return nombre;
}