#ifndef PERSONA_H
#define PERSONA_H

#pragma once
#include <iostream>
#include <string>
using namespace std;
class Persona
{
public:
    Persona(string nuevo);
    ~Persona();
    string verNombre();

private:
    string nombre;
};

#endif