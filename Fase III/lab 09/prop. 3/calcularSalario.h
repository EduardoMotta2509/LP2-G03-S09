#ifndef CALCULARSALARIO_H
#define CALCULARSALARIO_H

#include <iostream>
using namespace std;

class CalcularSalario{
public:
    CalcularSalario() {}

    virtual double calcularSalario() = 0;

    ~CalcularSalario() {}
};
#endif