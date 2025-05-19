#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Figura.h"

class Rectangulo : public Figura {
private:
    double base, altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}

    void dibujar() const override {
        cout << "Dibujando un rectangulo de " << base << " x " << altura << endl;
    }

    double calcularArea() const override {
        return base * altura;
    }
};

#endif
