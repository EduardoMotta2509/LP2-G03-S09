#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
using namespace std;

class Empleado {
public:
    virtual double calcularSalario() const = 0;
    virtual ~Empleado() {}
};

#endif
