#include "Mision.h"
#include "Avion.h"
#include <iostream>

using namespace std;

int main(){
    Mision m1("EEUU",4,50);
    Avion a1(5000, 5000, 100,1000);
    a1.simularMision(m1);
    a1.mostrarInfo();
    m1.mostrarMision();
    return 0;
}