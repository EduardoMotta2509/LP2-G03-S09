#include <iostream>
#include "Circulo.h"
#include "Cuadrado.h"
#include "TrianguloRectangulo.h"

using namespace std;

int main(){
    Circulo c1(12.56);
    Cuadrado c2(23.1);
    TrianguloRectangulo t1(12.2, 2);

    c1.mostrarInfo();
    c2.mostrarInfo();
    t1.mostrarInfo();

    return 0;
}

