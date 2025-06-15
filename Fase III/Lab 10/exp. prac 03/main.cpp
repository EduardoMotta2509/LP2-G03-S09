#include <iostream>
#include <vector>
#include "SistemaEntrega.h"
using namespace std;

int main(){
    vector<int> paradasInt = {10, 20, 30};
    SistemaEntrega<int> sistema1(0, 50, paradasInt);
    sistema1.generarInforme();
    sistema1.agregarPuntoParada(40);
    sistema1.generarInforme();

    vector<float> paradasFloat = {30.5, 70.2, 40.3};
    SistemaEntrega<float> sistema2(1.0, 10.0, paradasFloat);
    sistema2.generarInforme();

    return 0;
}