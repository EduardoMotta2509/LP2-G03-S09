#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Forma.h"

class Rectangulo : public Forma {
private:
    double base, altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}
    double calcularPerimetro() override {
        return 2 * (base + altura);
    }
};

#endif
