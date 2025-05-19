#ifndef PENTAGONO_H
#define PENTAGONO_H

#include "Figura.h"
#include <cmath>

class Pentagono : public Figura {
private:
    double lado, apotema;
public:
    Pentagono(double l, double a) : lado(l), apotema(a) {}
    double calcularArea() {
        return (5 * lado * apotema) / 2.0;
    }
};

#endif
