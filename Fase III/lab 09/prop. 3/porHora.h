#ifndef PORHORA_H
#define PORHORA_H

#include <iostream>
#include "calcularSalario.h"
using namespace std;

class PorHora: public CalcularSalario {
public:
    double pagoPorHora;
    double horasTrabajadas;

    PorHora(double p, double h): pagoPorHora(p), horasTrabajadas(h) {}

    double calcularSalario() override {
        cout<<"El salario es: "<<pagoPorHora*horasTrabajadas<<endl;
        return pagoPorHora*horasTrabajadas;
    }
};
#endif