#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Forma.h"

class Triangulo : public Forma {
private:
    double lado1, lado2, lado3;
public:
    Triangulo(double a, double b, double c) : lado1(a), lado2(b), lado3(c) {}
    double calcularPerimetro() override {
        return lado1 + lado2 + lado3;
    }
};

#endif
