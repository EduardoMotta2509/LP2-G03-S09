#include <iostream>
using namespace std;

#include "Ave.h"
#include "Mamifero.h"
#include "Reptil.h"

int main(){
    Ave canario("rojo", "corto");
    Mamifero leon("carne", "sabana");
    Reptil serpiente(true, "reptar");

    canario.comer();
    canario.dormir();
    canario.desplazarse();

    leon.comer();
    leon.dormir();
    leon.desplazarse();

    serpiente.comer();
    serpiente.dormir();
    serpiente.desplazarse();

    return 0;
}


Comiendo alpiste...
Durmiendo en su nido...
Volando...
Comiendo carne...
Durmiendo en sabana...
Caminando...
Comiendo insectos...
Durmiendo en su escondite...
El reptil empezó a reptar...
