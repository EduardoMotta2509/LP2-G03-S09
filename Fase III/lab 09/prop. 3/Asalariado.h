#ifndef ASALARIADO_H
#define ASALARIADO_H

#include <iostream>
#include "calcularSalario.h"
using namespace std;

class Asalariado: public CalcularSalario {
public:
    double salario;

    Asalariado(double s): salario(s) {}

    double calcularSalario() override {
        cout<<"El salario es: "<<salario<<" al mes"<<endl;
        return salario;
    }
};
#endif