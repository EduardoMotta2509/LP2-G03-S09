#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura.h"
#define PI 3.1416

class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() {
        return PI * radio * radio;
    }
};

#endif
