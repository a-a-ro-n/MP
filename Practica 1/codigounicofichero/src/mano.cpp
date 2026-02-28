#include "Mano.hpp"

#include <iostream>
#include <string>
using namespace std;

Mano::Mano(){}

Mano::Mano(const Mano& orig){}

Mano::~Mano(){}

void Mano::anaideCarta(Carta & nuevacarta)
{
     cartas[numCartas] = nuevacarta;
     numCartas++;
}

void Mano::descartaCarta(const int pos)
{
        for(int i = pos; i < numCartas;i++){
            cartas[i] = cartas[i+1];
        }
         numCartas--;
}

void Mano::cambiaCarta(const Carta & nuevacarta,const int pos)
{
        cartas[pos] = nuevacarta;
}

string Mano::to_string() const
{
        string cadcartas="";
        for(int i = 0; i < numCartas;i++){
            cadcartas = cadcartas + std::to_string(cartas[i].numero())+ " de "+
                    cartas[i].paloCartastring() + "\n";
        }
        return cadcartas;
}

int  Mano::numeroCartas() const
{
        return numCartas;
}

const Carta & Mano::carta(int i) const
{
        return cartas[i];
}

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




