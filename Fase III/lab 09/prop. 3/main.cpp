#include <iostream>
using namespace std;

#include "Asalariado.h"
#include "Comisionista.h"
#include "porHora.h"

int main(){
    Asalariado a1(2000.5);
    Comisionista c1(200.5, 3000.6);
    PorHora p1(50.6, 70);

    a1.calcularSalario();
    c1.calcularSalario();
    p1.calcularSalario();

    return 0;
}



