#ifndef COMISIONISTA_H
#define COMISIONISTA_H

#include <iostream>
#include "calcularSalario.h"
using namespace std;

class Comisionista: public CalcularSalario {
public:
    double comision;
    double salario;

    Comisionista(double c, double s): comision(c), salario(s) {}

    double calcularSalario() override {
        cout<<"El salario es: "<<comision+salario<<endl;
        return comision+salario;
    }
};
#endif