#include <iostream>
using namespace std;

#include "Vehiculo.h"
#include "Automovil.h"
#include "Motocicleta.h"

int main(){
    Automovil a1("Toyota", "Modelo23", 2025, 20000.70, 6, "Electrico");
    a1.mostrarAutomovil();

    Motocicleta m1("Kawasaki", "Modelo 9", 2024, 10000.60, 500);
    m1.mostrarMotocicleta();
    return 0;
}