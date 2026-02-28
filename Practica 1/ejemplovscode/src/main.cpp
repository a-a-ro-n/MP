#include <iostream>
#include "Persona.h"

using namespace std;

int main(){
    int * v = new int [3];
    v[0] = 2;
    v[1] = 3;
    v[2] = 5;
    cout << "Hola mundo" << " " << v[0] << " " << v[1] 
    << " " << v[2];
    Persona p("Pedro");
    cout << endl << p.verNombre() << endl;
    
}
