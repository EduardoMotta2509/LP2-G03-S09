#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>
using namespace std;

class Figura {
public:
    virtual void dibujar() const = 0;
    virtual double calcularArea() const = 0;
    virtual ~Figura() {}
};

#endif
