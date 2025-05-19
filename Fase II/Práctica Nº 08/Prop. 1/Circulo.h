#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura.h"
#define PI 3.14159

class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}

    void dibujar() const override {
        cout << "Dibujando un circulo con radio " << radio << endl;
    }

    double calcularArea() const override {
        return PI * radio * radio;
    }
};

#endif
