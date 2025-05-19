#ifndef CIRCULO_H
#define CIRCULO_H

#include "Forma.h"

class Circulo : public Forma {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularPerimetro() override {
        return 2 * 3.1415 * radio;
    }
};

#endif
